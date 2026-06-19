import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int n;
        boolean[][] can;
        long[][][] skipOne;
        long[][][][] twoSeg;
        long[][][] pointAndSeg;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.readInt();
            can = new boolean[2 * n][2 * n];
            for (int i = 0; i < 2 * n; i++) {
                for (int j = 0; j < 2 * n; j++) {
                    can[i][j] = in.readCharacter() == '1';
                }
            }
            skipOne = new long[2 * n][2 * n][2 * n];
            twoSeg = new long[2 * n][2 * n][2 * n][2 * n];
            pointAndSeg = new long[2 * n][2 * n][2 * n];
            ArrayUtils.fill(skipOne, -1);
            ArrayUtils.fill(twoSeg, -1);
            ArrayUtils.fill(pointAndSeg, -1);
            long answer = 0;
            for (int i = 1; i < 2 * n; i++) {
                if (can[0][i]) {
                    answer += goSkipOne(1, i, 2 * n - 1);
                }
            }
            out.printLine(answer);
        }

        private long goSkipOne(int from, int skip, int to) {
            if (skipOne[from][skip][to] != -1) {
                return skipOne[from][skip][to];
            }
            if (from == to) {
                return skipOne[from][skip][to] = 1;
            }
            skipOne[from][skip][to] = 0;
            for (int i = from; i < skip; i++) {
                for (int j = skip + 1; j <= to; j++) {
                    skipOne[from][skip][to] += goTwoSeg(from, i, j, to) * goSkipOne(i + 1, skip, j - 1);
                }
            }
            return skipOne[from][skip][to];
        }

        private long goTwoSeg(int f1, int t1, int f2, int t2) {
            if (twoSeg[f1][t1][f2][t2] != -1) {
                return twoSeg[f1][t1][f2][t2];
            }
            twoSeg[f1][t1][f2][t2] = 0;
            for (int i = f1; i <= t1; i++) {
                twoSeg[f1][t1][f2][t2] += goSkipOne(f1, i, t1) * goPointAndSeg(i, f2, t2);
            }
            return twoSeg[f1][t1][f2][t2];
        }

        private long goPointAndSeg(int point, int from, int to) {
            if (pointAndSeg[point][from][to] != -1) {
                return pointAndSeg[point][from][to];
            }
            pointAndSeg[point][from][to] = 0;
            for (int i = from; i <= to; i++) {
                if (can[point][i]) {
                    pointAndSeg[point][from][to] += goSkipOne(from, i, to);
                }
            }
            return pointAndSeg[point][from][to];
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static class ArrayUtils {
        public static void fill(long[][] array, long value) {
            for (long[] row : array) {
                Arrays.fill(row, value);
            }
        }

        public static void fill(long[][][] array, long value) {
            for (long[][] row : array) {
                fill(row, value);
            }
        }

        public static void fill(long[][][][] array, long value) {
            for (long[][][] row : array) {
                fill(row, value);
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public char readCharacter() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return (char) c;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

