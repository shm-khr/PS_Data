import java.util.Scanner;

public class Main {

	static long mod = 1000000007;

	public static void main(String[] args) {
		// AtCoder_A
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int H = sc.nextInt();
		int W = sc.nextInt();
		int N = sc.nextInt();
	    // Scannerクラスのインスタンスをクローズ
		sc.close();
		// 出力
		System.out.println(Math.min((N-1)/H+1, (N-1)/W+1));
	}
}
