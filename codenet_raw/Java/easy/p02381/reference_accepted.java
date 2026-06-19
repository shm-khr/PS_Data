import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        int n;
        double[] s;
        double m;
        double a;
        int i;
        while((n=sc.nextInt())!=0){
            s=null;
            s=new double[n];
            m=0;
            for(i=0;i<n;i++){
                s[i]=sc.nextDouble();
                m+=s[i];
            }
            m/=n;
            a=0;
            for(i=0;i<n;i++){
                a+=Math.pow(s[i]-m,2);
            }
            a/=n;
            System.out.println(Math.sqrt(a));
        }
    }
}

