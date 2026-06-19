import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();

		//個数を求めるだけだから、全探索不要。
		//基本的に、a,b,cすべてがkの倍数のとき、条件を満たす。
		//例外として、nが偶数、a,b,cすべてが (sk - k / 2) (sは任意の正の整数)で
		//表されるとき、条件を満たす。

		//n以下のkの倍数の個数を求める。
		int multNum = n / k;
		long count = multNum;
		count *= multNum;
		count *= multNum;

		//n以下の(sk - k / 2) (sは任意の正の整数)の個数を求める。
		long exCount = 0;
		if (k % 2 == 0) {
			int exNum = (multNum * k + k / 2 <= n) ? multNum + 1: multNum;
			exCount = exNum;
			exCount *= exNum;
			exCount *= exNum;
		}

		//出力する
		System.out.println(count + exCount);

	}

}
