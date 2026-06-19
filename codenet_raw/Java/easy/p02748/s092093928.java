import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int m = sc.nextInt();
		int[] A = new int[a];
		int mina=100000;
		int[] B = new int[b];
		int minb=100000;
		int min = 0;
		for(int i=0; i<a; i++) {
			A[i] = sc.nextInt();
			mina = A[0];
			if(mina>A[i]) {
				mina = A[i];
			}
		}
		for(int i=0; i<b; i++) {
			B[i] = sc.nextInt();
			minb = B[0];
			if(minb>B[i]) {
				minb = B[i];
			}
		}
		min = mina + minb;
		for(int i=0; i<m; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			int c = sc.nextInt();
			int coupon = A[x-1]+B[y-1]-c;
			if(min > coupon) {
				min = coupon;
			}
		}
		
		System.out.println(min);
	}

}
