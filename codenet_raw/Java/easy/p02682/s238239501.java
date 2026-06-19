import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		
		Scanner in = new Scanner(System.in);
		
		long A = in.nextLong();
		long B = in.nextLong();
		long C = in.nextLong();
		long K = in.nextLong();
		
		
		//[1,2,3] K=4
		
		if (K<A) {
			System.out.println(K);
		} else {
			if (K==A) {
				System.out.println(A);
			} else if (A+B >= K) {
				System.out.println(A);
			} else {
				System.out.println(A - (K-A+B));
			}
		}
		
		
	}
}
