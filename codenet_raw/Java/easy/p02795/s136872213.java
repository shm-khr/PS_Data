import java.util.*;

public class HelloWorld {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int N,M,A;
        N=sc.nextInt();
        M=sc.nextInt();
        A=sc.nextInt();
        int i=0;
        if(N>=M)
        i=A/N;
        else
        i=A/M;
        System.out.println(i);
    }
}