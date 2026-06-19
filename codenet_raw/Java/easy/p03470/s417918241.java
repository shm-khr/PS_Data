import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = Integer.parseInt(sc.next());

        Set<Integer> dSet = new HashSet<Integer>();

        for (int i=0; i<N; i++) {
            dSet.add(Integer.valueOf(sc.next()));
            System.out.println(dSet);
        }
        System.out.println(dSet.size());
    }
}
