import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int K = Integer.parseInt(sc.next());
        long INF = 5_000_000_000_000_000_000L;
        ArrayList<int[]> point_x = new ArrayList<int[]>();
        Comparator<int[]> comparator_x = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        };
        Comparator<int[]> comparator_y = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[1], o2[1]);
            }
        };
        for (int i=0;i<N;i++) {
            int x = Integer.parseInt(sc.next());
            int y = Integer.parseInt(sc.next());
            int[] add = {x, y, i};
            point_x.add(add);
        }
        ArrayList<int[]> point_y = new ArrayList<int[]>(point_x);
        Collections.sort(point_x, comparator_x);
        Collections.sort(point_y, comparator_y);
        // for (int[] array : point_x) {
        //     System.out.println("x " + Arrays.toString(array));
        // }
        // for (int[] array : point_y) {
        //     System.out.println("y " + Arrays.toString(array));
        // }
        long ans = INF;
        for (int wid=2;wid<=K;wid++) {
            for (int i=0;i+wid<=N;i++) {
                int[] flag = new int[N];
                for (int j=i;j<=i+wid;j++) {
                    flag[point_x.get(j)[2]]=1;
                }
                for (int j=0;j+wid<=N;j++) {
                    int cnt=0;
                    for (int k=j;k<=j+wid;k++) {
                        // System.out.println("k wid " + k + " " + wid);
                        if (flag[point_y.get(k)[2]]==1) {
                            cnt++;
                        }
                    }
                    if (cnt>=K) {
                        ans = Math.min(ans, (long)(point_x.get(i+wid-1)[0]-point_x.get(i)[0])*(point_y.get(j+wid-1)[1]-point_y.get(j)[1]));
                    }
                }
            }
        }
        System.out.println(ans);
    }
}