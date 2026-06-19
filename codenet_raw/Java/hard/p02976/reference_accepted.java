import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            BEvenDegrees solver = new BEvenDegrees();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class BEvenDegrees {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            Edge[] edges = new Edge[m];

            DSU dsu = new DSU(n);
            for (int i = 0; i < m; i++) {
                Edge e = new Edge();
                e.a = nodes[in.readInt() - 1];
                e.b = nodes[in.readInt() - 1];
                e.toA = true;
                e.b.xor ^= 1;
                edges[i] = e;

                if (dsu.find(e.a.id) == dsu.find(e.b.id)) {
                    continue;
                }
                dsu.merge(e.a.id, e.b.id);

                e.a.adj.add(e);
                e.b.adj.add(e);
            }

            if (1 == dfs(nodes[0], null)) {
                out.println(-1);
                return;
            }

            for (Edge e : edges) {
                if (!e.toA) {
                    Node tmp = e.a;
                    e.a = e.b;
                    e.b = tmp;
                }

                out.append(e.b.id + 1).append(' ').append(e.a.id + 1).println();
            }
        }

        public int dfs(Node root, Edge p) {
            for (Edge e : root.adj) {
                if (e == p) {
                    continue;
                }
                Node node = e.other(root);
                int inv = dfs(node, e);
                if (inv == 1) {
                    e.toA = !e.toA;
                    root.xor ^= 1;
                }
            }

            return root.xor;
        }

    }

    static class Edge {
        Node a;
        Node b;
        boolean toA;

        public Node other(Node x) {
            return a == x ? b : a;
        }

    }

    static class DSU {
        protected int[] p;
        protected int[] rank;

        public DSU(int n) {
            p = new int[n];
            rank = new int[n];
            reset();
        }

        public final void reset() {
            for (int i = 0; i < p.length; i++) {
                p[i] = i;
                rank[i] = 0;
            }
        }

        public final int find(int a) {
            if (p[a] == p[p[a]]) {
                return p[a];
            }
            return p[a] = find(p[a]);
        }

        public final void merge(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return;
            }
            if (rank[a] == rank[b]) {
                rank[a]++;
            }

            if (rank[a] < rank[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }

            p[b] = a;
        }

    }

    static class Node {
        List<Edge> adj = new ArrayList<>();
        int xor;
        int id;

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }
}

