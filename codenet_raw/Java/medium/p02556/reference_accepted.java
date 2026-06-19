import java.util.Scanner;

public class Main {
	// Shojin
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			long plusMax = 0;
			long plusMin = Long.MAX_VALUE;
			long minusMax = 0;
			long minusMin = Long.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				long x = sc.nextLong();
				long y = sc.nextLong();
				plusMax = Math.max(plusMax, x + y);
				plusMin = Math.min(plusMin, x + y);
				minusMax = Math.max(minusMax, y - x);
				minusMin = Math.min(minusMin, y - x);
			}
			System.out.println(Math.max(plusMax - plusMin, minusMax - minusMin));
		}
	}
}