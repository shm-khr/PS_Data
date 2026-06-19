import java.util.*;

public class Main {

	static int days(int Y, int M, int D) {
		int days = 0;

		for (int y = 1; y < Y; ++y) {
			if (y % 3 == 0) {
				// 3年，6年，9年，…のように，3で割り切れる年には，小の月は訪れず，10すべての月を大の月とする．
				days += 20 * 10;
			} else {
				// ふつうの年は，1月が大の月，2月は小の月，3月は大の月，そして最後の10月は小の月というように，大の月と小の月が交互に訪れる
				days += 19 * 5 + 20 * 5;
			}
		}

		for (int m = 1; m < M; ++m) {
			if (Y % 3 == 0 || m % 2 == 1) {
				days += 20;
			} else {
				days += 19;
			}
		}

		days += D;

		return days;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		int premium = days(1000, 1, 1);

		for (int i = 0; i < n; ++i) {
			int Y = sc.nextInt();
			int M = sc.nextInt();
			int D = sc.nextInt();
			System.out.println(premium - days(Y, M, D));
		}
	}
}

