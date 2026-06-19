import java.util.*;
public class Main {
    public static void main(String [] args){
        Scanner input = new Scanner(System.in);
        
        int N = input.nextInt();
        int a[] = new int[N];
        int tf=0;
        int x =0;
        for(int i = 0; i<a.length; i++){
            a[i] = input.nextInt();
        tf += a[i];
        }
        tf = (int)Math.ceil((double)tf/N);
        //System.out.println(tf);
        for(int i = 0; i<a.length; i++){
            x+=(int)Math.pow(a[i]-tf, 2);
        }
         System.out.println(x);
    }
}