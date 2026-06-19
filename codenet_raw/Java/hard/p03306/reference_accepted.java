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
            EGraph solver = new EGraph();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EGraph {
        long val = Long.MIN_VALUE;
        boolean valid = true;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
            }
            for (int i = 0; i < m; i++) {
                Node a = nodes[in.readInt() - 1];
                Node b = nodes[in.readInt() - 1];
                Edge e = new Edge();
                e.a = a;
                e.b = b;
                e.w = in.readInt() - 2;
                a.adj.add(e);
                b.adj.add(e);
            }

            dfs(nodes[0], null, new DoubleLinearFunction(1, 0));
            long l = 0;
            long r = Integer.MAX_VALUE;
            for (Node node : nodes) {
                DoubleLinearFunction df = node.func;
                if (df.a == 0) {
                    if (df.b < 0) {
                        valid = false;
                    }
                    continue;
                }
                if (df.a < 0) {
                    r = Math.min(r, DigitUtils.floorDiv((long) -df.b, (long) df.a));
                } else {
                    l = Math.max(l, DigitUtils.ceilDiv((long) -df.b, (long) df.a));
                }
            }

            if (l > r) {
                valid = false;
            }
            if (!valid) {
                out.println(0);
                return;
            }
            if (val != Long.MIN_VALUE) {
                if (val >= l && val <= r) {
                    out.println(1);
                } else {
                    out.println(0);
                }
                return;
            }

            out.println(r - l + 1);
        }

        public void dfs(Node root, Edge p, DoubleLinearFunction func) {
            if (root.func != null) {
                DoubleLinearFunction delta = DoubleLinearFunction.subtract(root.func, func);
                if (delta.a == 0) {
                    if (delta.b == 0) {
                        return;
                    }
                    valid = false;
                } else {
                    if (-(long) delta.b % (long) delta.a != 0) {
                        valid = false;
                    }
                    if (val != Long.MIN_VALUE && -(long) delta.b / (long) delta.a != val) {
                        valid = false;
                    }
                    val = -(long) delta.b / (long) delta.a;
                }
                return;
            }
            root.func = func;
            for (Edge e : root.adj) {
                if (e == p) {
                    continue;
                }
                dfs(e.other(root), e, DoubleLinearFunction.subtract(
                        new DoubleLinearFunction(0, e.w), root.func));
            }
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long floorDiv(long a, long b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static long ceilDiv(long a, long b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            long c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
        }

    }

    static class Edge {
        Node a;
        Node b;
        int w;

        Node other(Node x) {
            return a == x ? b : a;
        }

    }

    static class DoubleLinearFunction {
        public final double a;
        public final double b;

        public DoubleLinearFunction(double a, double b) {
            this.a = a;
            this.b = b;
        }

        public static DoubleLinearFunction subtract(DoubleLinearFunction a, DoubleLinearFunction b) {
            return new DoubleLinearFunction(a.a - b.a, a.b - b.b);
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof DoubleLinearFunction)) {
                return false;
            }
            DoubleLinearFunction function = (DoubleLinearFunction) obj;
            return function.a == a && function.b == b;
        }

        public int hashCode() {
            return Double.hashCode(a) * 31 + Double.hashCode(b);
        }

        public String toString() {
            if (b >= 0) {
                return a + "x+" + b;
            }
            return a + "x" + b;
        }

    }

    static class Node {
        List<Edge> adj = new ArrayList<>();
        DoubleLinearFunction func;

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

        public FastOutput append(long c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println(long c) {
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

