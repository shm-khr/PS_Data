
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long n = sc.nextLong();

		long max = Long.MIN_VALUE;
		for(long x=n; x>=1; x--) {
			if(x/b==0 || x%b == b-1) {
				System.out.println((a*x)/b - a *(x/b));
				sc.close();
				return;
			}
		}
		System.out.println(max);
		sc.close();
	}


}