import java.util.*;

public class Main {
	Scanner sc = new Scanner(System.in);
	final int MOD = 998244353;
	final int MAX = Integer.MAX_VALUE;
	final long LMAX = Long.MAX_VALUE;
	int len = (int)1e6 + 1;
	
	
	void doIt() {
		int N = sc.nextInt();
		int M = sc.nextInt();
		int m1 = M, m2;
		if(m1 % 2 == 0)m1++;
		m2 = m1 + (2 * M + 1 - m1) / 2;
		m1 = m1 / 2 + 1;
		//System.out.println(m1 + " "  + m2);
		for(int i = 1; i < m1; i++) {
			System.out.println((m1 - i) + " " + (m1 + i));
		}
		for(int i = 1; i < m1; i++) {
			System.out.println((m2 - i + 1) + " " + (m2 + i));
		}
	}
	
	
	public static void main(String[] args) {
		new Main().doIt();
	}

}
