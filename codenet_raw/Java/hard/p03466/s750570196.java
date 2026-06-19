import java.util.*;

public class Main {
	public static void main(String[] argv) {
		Scanner sc = new Scanner(System.in);
		long Tests = sc.nextLong();
		while (Tests > 0) {
			long a = sc.nextLong(), b = sc.nextLong();
			long l = sc.nextLong(), r = sc.nextLong();
			long len = (Math.max(a, b) - 1) / (Math.min(a, b) + 1) + 1;
			long lena, lenb;
			if (a >= len * b) {
				lena = a + b; lenb = 0;
			} else if (b >= len * a) {
				lena = 0; lenb = a + b;
			} else {
				lena = (len * a - b) / (len - 1);
				lenb = (len * b - a) / (len - 1);
			}
			boolean B = a - lena + lena / (len + 1) - lenb / (len + 1) == 0;
			for (long i = l - 1; i < r; ++ i) {
				if (i < a && i % (len + 1) == len) System.out.print('B');
				else if (i >= a + b - lenb && (a + b - i - 1) % (len + 1) != len) System.out.print('B');
				else if (B) System.out.print('B');
				else System.out.print('A');
			}
			System.out.println();
			Tests --;
		}
	}
}