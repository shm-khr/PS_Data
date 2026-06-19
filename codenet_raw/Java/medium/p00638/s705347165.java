import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
    private static void solve() {
        final Scanner scanner = new Scanner(System.in);

        while (true) {
            final int n = scanner.nextInt();
            if (n == 0) {
                break;
            }
            int[][] islands = new int[n][2];
            for (int i = 0; i < n; i++) {
                islands[i][0] = scanner.nextInt();
                islands[i][1] = scanner.nextInt();
            }
            Arrays.sort(islands, new Comparator<int[]>() {
                public int compare(int[] o1, int[] o2) {
                    if (o1[1] == o2[1]) {
                        return o1[0] == o2[0] ? 0 : (o1[0] > o2[0] ? 1 : -1);
                    } else {
                        return o1[1] > o2[1] ? 1 : -1;
                    }
                }
            });
            int sum = 0;
            boolean possible = true;
            for (int i = 0; i < n; i++) {
                sum += islands[i][0];
                if (sum > islands[i][1]) {
                    possible = false;
                }
            }
            System.out.println(possible ? "YES" : "NO");
        }
    }

    public static void main(String... args) {
        solve();
    }
}