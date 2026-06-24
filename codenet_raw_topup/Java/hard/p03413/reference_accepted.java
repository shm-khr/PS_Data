import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
 * 
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
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
            BothSidesMerger solver = new BothSidesMerger();
            solver.solve(1, in, out);
            out.close();
        }
    }
    static class BothSidesMerger {
        int n;
        int[] a;
        long[][][] dp;
        long lInf = (long) 1e18;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt();
            }
            dp = new long[n][n][3];
            SequenceUtils.deepFill(dp, -1L);

            long ans = -lInf;
            int maxI = -1;
            int maxK = -1;
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < 3; k++) {
                    if (dp(i, n - 1, k) > ans) {
                        ans = dp(i, n - 1, k);
                        maxI = i;
                        maxK = k;
                    }
                }
            }

            out.println(ans);
            int[] vals = new int[n];

            trace(vals, maxI, n - 1, maxK);

            IntList valDeque = new IntList();
            valDeque.addAll(vals, maxI, n - maxI);


            IntList op = new IntList(n);
            for (int i = 0; i < maxI; i++) {
                op.add(1);
            }

            while (valDeque.tail() == 0) {
                op.add(valDeque.size());
                valDeque.pop();
            }

            valDeque.pop();
            while (!valDeque.isEmpty()) {
                while (valDeque.get(valDeque.size() - 2) == 0) {
                    op.add(valDeque.size() - 1);
                    valDeque.pop();
                    valDeque.pop();
                }
                if (valDeque.size() >= 2 && valDeque.get(valDeque.size() - 2) == 1) {
                    op.add(valDeque.size());
                    valDeque.pop();
                    valDeque.pop();
                }
            }

            out.println(op.size());
            for (int i = 0; i < op.size(); i++) {
                out.println(op.get(i));
            }
        }

        public void trace(int[] vals, int i, int j, int k) {
            if (j == i) {
                vals[j] = 1;
                return;
            }
            if (k == 2) {
                vals[j] = 1;
                trace(vals, i, j - 1, 1);
                return;
            }
            if (k == 1) {
                if (dp(i, j - 1, 0) == dp(i, j, k)) {
                    trace(vals, i, j - 1, 0);
                } else {
                    trace(vals, i, j - 1, 2);
                }
                return;
            }
            trace(vals, i, j - 1, 1);
        }

        public long dp(int i, int j, int k) {
            if (dp[i][j][k] == -1) {
                if (i == j) {
                    dp[i][j][k] = k == 2 ? a[i] : -lInf;
                    return dp[i][j][k];
                }
                if (k == 2) {
                    dp[i][j][k] = a[j] + dp(i, j - 1, 1);
                } else if (k == 1) {
                    dp[i][j][k] = Math.max(dp(i, j - 1, 0), dp(i, j - 1, 2));
                } else {
                    dp[i][j][k] = dp(i, j - 1, 1);
                }
            }
            return dp[i][j][k];
        }

    }
    static class SequenceUtils {
        public static void deepFill(Object array, long val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof long[]) {
                long[] longArray = (long[]) array;
                Arrays.fill(longArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
            }
        }

    }
    static class IntList {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntList(IntList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntList() {
            this(0);
        }

        private void ensureSpace(int need) {
            int req = size + need;
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException();
            }
        }

        public int get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(int x) {
            ensureSpace(1);
            data[size++] = x;
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public int tail() {
            checkRange(0);
            return data[size - 1];
        }

        public int pop() {
            return data[--size];
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
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
    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(int c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput println(long c) {
            cache.append(c).append('\n');
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

    }
}

