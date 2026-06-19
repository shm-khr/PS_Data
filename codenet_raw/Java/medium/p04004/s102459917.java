import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
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
            PrintWriter out = new PrintWriter(outputStream);
            TaskD solver = new TaskD();
            solver.solve(1, in, out);
            out.close();
        }
    }
    static class TaskD {
        public void solve(int testNumber, FastInput in, PrintWriter out) {
            NumberTheory.Modular mod = new NumberTheory.Modular((int) 1e9 + 7);
            NumberTheory.Power power = new NumberTheory.Power(mod);
            NumberTheory.Factorial fact = new NumberTheory.Factorial(3000, mod);

            int n = in.readInt();
            int m = in.readInt();
            int k = in.readInt();

            int ans = 0;
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= k; j++) {
                    int cnt = fact.fact(n - 1 + i + j);
                    cnt = mod.mul(cnt, fact.invFact(n - 1));
                    cnt = mod.mul(cnt, fact.invFact(i));
                    cnt = mod.mul(cnt, fact.invFact(j));
                    int remain = m + k - i - j;
                    cnt = mod.mul(cnt, power.pow(3, remain));

                    ans = mod.plus(ans, cnt);
                }
            }

            out.println(ans);
        }

    }
    static class NumberTheory {
        public static class Modular {
            int m;

            public Modular(int m) {
                this.m = m;
            }

            public int valueOf(int x) {
                x %= m;
                if (x < 0) {
                    x += m;
                }
                return x;
            }

            public int valueOf(long x) {
                x %= m;
                if (x < 0) {
                    x += m;
                }
                return (int) x;
            }

            public int mul(int x, int y) {
                return valueOf((long) x * y);
            }

            public int plus(int x, int y) {
                return valueOf(x + y);
            }

            public String toString() {
                return "mod " + m;
            }

        }

        public static class Power {
            final NumberTheory.Modular modular;

            public Power(NumberTheory.Modular modular) {
                this.modular = modular;
            }

            public int pow(int x, long n) {
                if (n == 0) {
                    return 1;
                }
                long r = pow(x, n >> 1);
                r = modular.valueOf(r * r);
                if ((n & 1) == 1) {
                    r = modular.valueOf(r * x);
                }
                return (int) r;
            }

        }

        public static class InverseNumber {
            int[] inv;

            public InverseNumber(int[] inv, int limit, NumberTheory.Modular modular) {
                this.inv = inv;
                inv[1] = 1;
                int p = modular.m;
                for (int i = 2; i <= limit; i++) {
                    int k = p / i;
                    int r = p % i;
                    inv[i] = modular.mul(-k, inv[r]);
                }
            }

            public InverseNumber(int limit, NumberTheory.Modular modular) {
                this(new int[limit + 1], limit, modular);
            }

        }

        public static class Factorial {
            int[] fact;
            int[] inv;

            public Factorial(int[] fact, int[] inv, NumberTheory.InverseNumber in, int limit,
                            NumberTheory.Modular modular) {
                this.fact = fact;
                this.inv = inv;
                fact[0] = inv[0] = 1;
                for (int i = 1; i <= limit; i++) {
                    fact[i] = modular.mul(fact[i - 1], i);
                    inv[i] = modular.mul(inv[i - 1], in.inv[i]);
                }
            }

            public Factorial(int limit, NumberTheory.Modular modular) {
                this(new int[limit + 1], new int[limit + 1], new NumberTheory.InverseNumber(limit, modular), limit,
                                modular);
            }

            public int fact(int n) {
                return fact[n];
            }

            public int invFact(int n) {
                return inv[n];
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
                    throw new RuntimeException(e);
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
}

