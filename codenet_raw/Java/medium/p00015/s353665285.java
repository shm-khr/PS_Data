import java.util.Scanner;
import java.math.BigInteger;

public class a0015{
    public static void main(String args[]) {
	Scanner scanner = new Scanner(System.in);
	int N = scanner.nextInt();
	for (int i = 0; i < N; i++) {
	    String a = scanner.next(), b = scanner.next();
	    BigInteger A = new BigInteger(a), B = new BigInteger(b);
	    BigInteger sum = A.add(B);
	    if ((sum.toString()).length() > 80) {
		System.out.println("overflow");
	    }
	    else {
		System.out.println(sum.toString());
	    }
	}
    }
}