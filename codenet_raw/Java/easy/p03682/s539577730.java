import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        Comparator<int[]> comparator = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        };
        ArrayList<int[]> X = new ArrayList<int[]>();
        ArrayList<int[]> Y = new ArrayList<int[]>();
        int[] x = new int[N];
        int[] y = new int[N];
        for (int i=0;i<N;i++) {
            x[i] = Integer.parseInt(sc.next());
            y[i] = Integer.parseInt(sc.next());
            int[] add_x = {x[i], i};
            int[] add_y = {y[i], i};
            X.add(add_x);
            Y.add(add_y);
        }
        Collections.sort(X, comparator);
        Collections.sort(Y, comparator);
        ArrayList<int[]> X_Y = new ArrayList<int[]>();
        for (int i=1;i<N;i++) {
            int[] add_x = {X.get(i)[0]-X.get(i-1)[0], X.get(i-1)[1], X.get(i)[1]};
            int[] add_y = {Y.get(i)[0]-Y.get(i-1)[0], Y.get(i-1)[1], Y.get(i)[1]};
            X_Y.add(add_x);
            X_Y.add(add_y);
        }
        Collections.sort(X_Y, comparator);
        long ans = 0L;
        HashSet<Integer> set = new HashSet<Integer>();
        for (int i=0;i<X_Y.size();i++) {
            int dist = X_Y.get(i)[0];
            int xx = X_Y.get(i)[1];
            int yy = X_Y.get(i)[2];
            if (set.contains(xx) && set.contains(yy)) continue;
            ans += dist;
            set.add(xx);
            set.add(yy);
        }
        System.out.println(ans);
    }
}