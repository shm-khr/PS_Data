import java.util.*;

class Main {
    static Scanner sc;
    static int n;
    static Pair[] items;
    public static void main(String[] args) {
        sc = new Scanner(System.in);
        n = sc.nextInt();
        items = new Pair[n];
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int l = sc.nextInt();
            items[i] = new Pair(x + l, l);
        }
        Arrays.sort(items);

        int ans = solve();
        System.out.println(ans);
    }

    public static int solve() {
        int[] dp = new int[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int left = items[i].x - 2 * items[i].y;
            if (items[i - 1].x <= left) {
                dp[i] = dp[i - 1] + 1;
                continue;
            }
            int index = binarySearch(left, i - 1);
            if (index == -1) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = Math.max(dp[index] + 1, dp[i - 1]);
            }
        }
        return dp[n - 1];
    }

    public static int binarySearch(int v, int r) {
        if (items[0].x > v) {
            return -1;
        }
        int l = 0;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (items[mid].x > v) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }
}

class Pair implements Comparable<Pair> {
    int x, y;

    Pair(int _x, int _y) {
        x = _x;
        y = _y;
    }

    public int compareTo(Pair b) {
        if (x > b.x) {
            return 1;
        } else if (x < b.x) {
            return -1;
        }

        if (y > b.y) {
            return 1;
        } else if (y < b.y) {
            return -1;
        }

        return 0;
    }
}