import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
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
            DBlackAndWhiteTree solver = new DBlackAndWhiteTree();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DBlackAndWhiteTree {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
            }
            for (int i = 0; i < n - 1; i++) {
                Node a = nodes[in.readInt() - 1];
                Node b = nodes[in.readInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }

            dfs(nodes[0], null);
            dfsForHeap(nodes[0], null, n);
            for (int i = 0; i < n; i++) {
                if (nodes[i].heap.get(0) == 1 && nodes[i].heap.get(1) == 1) {
                    out.println("First");
                    return;
                }
            }

            out.println("Second");
        }

        public void dfsForHeap(Node root, Node p, int total) {
            for (Node node : root.adj) {
                if (node == p) {
                    root.heap.add(total - root.size);
                    continue;
                }
                root.heap.add(node.size);
                dfsForHeap(node, root, total);
            }
        }

        public void dfs(Node root, Node p) {
            root.size = 1;
            for (Node node : root.adj) {
                if (node == p) {
                    continue;
                }
                dfs(node, root);
                root.size += node.size;
            }
        }

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

        public FastOutput append(String c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(String c) {
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

    static class IntegerFixedMinHeap {
        private int[] data;
        private static int[] buf = new int[1 << 8];

        public IntegerFixedMinHeap(int cap) {
            if (cap <= 0 || cap > buf.length) {
                throw new IllegalArgumentException();
            }
            data = new int[cap];
            clear();
        }

        public void clear() {
            Arrays.fill(data, Integer.MAX_VALUE);
        }

        public int get(int i) {
            return data[i];
        }

        public void add(int x) {
            if (data[data.length - 1] <= x) {
                return;
            }
            int j = data.length - 1;
            while (j > 0 && data[j - 1] > x) {
                data[j] = data[j - 1];
                j--;
            }
            data[j] = x;
        }

        public String toString() {
            return Arrays.toString(data);
        }

    }

    static class Node {
        List<Node> adj = new ArrayList<>();
        int size;
        IntegerFixedMinHeap heap = new IntegerFixedMinHeap(2);

    }
}

