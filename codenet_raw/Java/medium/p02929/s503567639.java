import java.io.PrintWriter;
import java.util.BitSet;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        new Solver().solve(in, out);

        in.close();
        out.flush();
    }

    private static class Solver {
        public void solve(Scanner in, PrintWriter out) {
            int n = in.nextInt();
            in.nextLine();
            String s = in.nextLine();
            char[] chars = s.toCharArray();
            BitSet bs = new BitSet(chars.length);
            for (int i = 0; i < chars.length; i++) {
                if (chars[i] == 'W') {
                    bs.set(i);
                }
            }

            if (bs.get(0) || bs.get(chars.length - 1)) {
                out.println(0);
                return;
            }

            BitSet ch = bs.get(1, chars.length);
            ch.xor(bs);

            BitSet lr = new BitSet(chars.length);
            int l = 1;
            long cases = 1;
            for (int i = 0; i < ch.length(); i++) {
                if (ch.get(i) ^ lr.get(i)) {
                    l++;
                    continue;
                }

                lr.set(i + 1);
                cases *= l;
                cases %= 1000000007;
                l--;
            }

            if (l != 0) {
                out.println(0);
                return;
            }

            for (int i = n; i > 0; i--) {
                cases *= i;
                cases %= 1000000007;
            }
            out.println(cases);
        }
    }
}