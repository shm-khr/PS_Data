import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        int cnt = 1;
        for(int i = 0; i < N; i++){
          a[i] = sc.nextInt();
        }
        int[] c = Arrays.stream(a).distinct().toArray();
        Arrays.sort(c);
        int min = c[0];
        for(int i = 0; i < c.length; i++){
          if(min < c[i]){
            cnt++;
          }
        }
        
        System.out.println(cnt);
    }
}
