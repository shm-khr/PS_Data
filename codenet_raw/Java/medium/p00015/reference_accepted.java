import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception{
        int n;
        BigDecimal a,b;
        int c;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(int i=0;i<n;i++){
            a = sc.nextBigDecimal();
            b = sc.nextBigDecimal();
            a = a.add(b);
            c = a.precision();
            if (c > 80){
                System.out.println("overflow");
            }else{
                System.out.println(a);
            }
        }
    }
}
