import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
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
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
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
            DMinMaxRepetition solver = new DMinMaxRepetition();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class DMinMaxRepetition {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int a = in.readInt();
            int b = in.readInt();
            int c = in.readInt();
            int d = in.readInt();

            Machine mac = new Machine(a, b);
            for (int i = c; i <= d; i++) {
                char ch = (char) mac.get(i);
                out.append(ch);
            }
            out.println();
        }

    }

    static abstract class IntBinarySearch {
        public abstract boolean check(int mid);

        public int binarySearch(int l, int r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            while (l < r) {
                int mid = DigitUtils.average(l, r);
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorDiv(int a, int b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static int ceilDiv(int a, int b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            int c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
        }

        public static int average(int a, int b) {
            int ans = (a / 2) + (b / 2);
            switch (a % 2 + b % 2) {
                case 2:
                    ans++;
                    break;
                case -1:
                case -2:
                    ans--;
                    break;
            }
            return ans;
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public String next() {
            return readString();
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

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
        }

    }

    static class Machine {
        int k;
        int p1;
        int t;
        int t2;

        private int atLeast(int a, int b) {
            if (b > a) {
                return DigitUtils.ceilDiv(b, a + 1);
            } else {
                return DigitUtils.ceilDiv(a, b + 1);
            }
        }

        private int atLeastBFirst(int a, int b) {
            if (b == 0) {
                return a;
            }
            if (b > a) {
                return atLeast(a, b);
            }
            return atLeastBFirst(a, b - 1);
        }

        public Machine(int a, int b) {
            //k * (a + 1) >= b
            k = atLeast(a, b);

            IntBinarySearch ibs = new IntBinarySearch() {

                public boolean check(int mid) {
                    mid = -mid;
                    if (mid == 0) {
                        return true;
                    }
                    int ar = a - mid * k;
                    int br = b - mid + 1;
                    if (ar < 0 || br < 0) {
                        return false;
                    }
                    if (ar >= br) {
                        return true;
                    }
                    if (atLeastBFirst(ar, br) > k) {
                        return false;
                    }
                    return true;
                }
            };

            p1 = -ibs.binarySearch(-(a / k), 0);
            ibs = new IntBinarySearch() {

                public boolean check(int mid) {
                    mid = -mid;
                    if (mid == 0) {
                        return true;
                    }
                    if (mid > k) {
                        return false;
                    }
                    int ar = a - p1 * k - mid;
                    int br = b - p1;
                    if (atLeastBFirst(ar, br) > k) {
                        return false;
                    }
                    return true;
                }
            };
            t = -ibs.binarySearch(-(a - p1 * k), 0);
            t2 = Math.max(0, b - p1 - k * (a - p1 * k - t));
        }

        public int get(int i) {
            if (i <= (k + 1) * p1) {
                return (i - 1) % (k + 1) < k ? 'A' : 'B';
            }
            i -= (k + 1) * p1;
            if (i <= t) {
                return 'A';
            }
            i -= t;
            if (i <= t2) {
                return 'B';
            }
            i -= t2;
            return (i - 1) % (k + 1) == 0 ? 'A' : 'B';
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

