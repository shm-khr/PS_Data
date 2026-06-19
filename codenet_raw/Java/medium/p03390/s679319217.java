import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q  = sc.nextInt();
        long a, b;
        for(int i=0; i<q; i++){
            long tmpa = sc.nextLong();
            long tmpb = sc.nextLong();
            if(tmpa > tmpb){
                a = tmpb;
                b = tmpa;
            }else{
                a = tmpa;
                b = tmpb;
            }
            long ans = 0;
            ans += (a-1) * 2;

            int count = 0;
            long score = a*b;
            for(int j=1; j<b; j++){
                if((a+j)*(a+j) < score){
                    count++;
                }else{
                    break;
                }
            }
            ans += count * 2;
            if((a + count) * (a+count + 1) < score) ans++;
            System.out.println(ans);
        }

    }
}