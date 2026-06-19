import java.util.Scanner;
public class Main {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		long A=sc.nextLong();
		long B=sc.nextLong();
		long N=sc.nextLong();
		long k=N/B;
		long max=0;
		if(k==0) {
			max=N*A/B;
		}
		else {
		for(long i=B-1;i<=N;i+=B) {
			long x=i/B;
			long m=i*A/B-A*x;
			max=Math.max(max, m);
		}
	}
		System.out.println(max);
	}
}
