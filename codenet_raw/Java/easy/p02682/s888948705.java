
import java.util.Scanner;

public class Main  {

	public static  void main(String[] args) {
		int A , B , C , K;
	int T = 0;
	Scanner sc = new Scanner(System.in);
	A = sc.nextInt();
	B = sc.nextInt();
	C = sc.nextInt();
	K = sc.nextInt();
	for(int D = K; D > 0 ;D--) {
		if(A != 0) {
			T = T + 1;
			A = A - 1;
		}else if(B != 0) {
			T = T + 0;
			B = B - 1;
		}else if(C != 0) {
			T = T - 1;
			C = C - 1;
		}
		}
	System.out.println( T);
	}

}
