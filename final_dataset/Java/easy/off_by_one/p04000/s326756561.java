import java.util.*;

public class Main {

    private static int H;
    private static int W;
    private static int N;
    private static Cord[] C;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        N = sc.nextInt();
        C = new Cord[N];
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            C[i] = new Cord(b, a);
        }

        long[] ans = solve();
        for (int i = 0; i < 10; i++) {
            System.out.println( ans[i] );
        }
    }


    private static long[] solve() {
        Set<Cord> all = new HashSet<>(Arrays.asList(C));
        Set<Cord> done = new HashSet<>(all.size());

        long[] ans = new long[10];
        ans[0] = (long)(W-3 + 1) * (H-3 + 1);

        for (int i = 0; i < N; i++) {
            Cord c = C[i];
            count(c, ans, all, done);
            done.add(c);
        }
        return ans;
    }

    private static void count(Cord target, long[] ans, Set<Cord> all, Set<Cord> done) {
        for (int x = target.x - 1; x <= target.x + 1 ; x++) {
            for (int y = target.y - 1; y <= target.y+ 1 ; y++) {
                Cord c = new Cord(x, y);

                int count = count2(c, all, done);
                if( count != -1 ) {
                    ans[count]++;
                    ans[0]--;
                }
            }
        }
    }

    private static int count2(Cord center, Set<Cord> all, Set<Cord> done) {
        int cnt = 0;
        for (int x = center.x - 1; x <= center.x + 1 ; x++) {
            for (int y = center.y - 1; y <= center.y + 1 ; y++) {
                if( !xInRange(x) || !yInRange(y) ) return -1;

                Cord c = new Cord(x, y);
                if( done.contains(c) ) return -1;

                if( all.contains(c) ) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    private static boolean xInRange(int x) {
        return 1 <= x && x <= W;
    }

    private static boolean yInRange(int y) {
        return 1 <= y && y <= H;
    }

    private static class Cord {

        private final int x;
        private final int y;

        public Cord(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Cord cord = (Cord) o;
            return x == cord.x &&
                    y == cord.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        public String toString() {
            return "(" +x + "," + y + ")";
        }
    }
}