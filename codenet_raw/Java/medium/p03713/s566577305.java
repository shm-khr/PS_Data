import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

	/** 何分割するか */
	private static final int N = 3;

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			long h = scanner.nextLong();
			long w = scanner.nextLong();
			long[] s = new long[N];
			System.out.println(getResult(Math.max(h, w), Math.min(h, w), s, N));
		}
	}

	/**
	 * @param h 高さ
	 * @param w 幅 w<=h
	 * @param s 結果の配列
	 * @param n 何分割するか
	 * @return 結果の最大値と最小値の差分
	 */
	private static long getResult(final long h, final long w, final long[] s, int n) {
		if (1 == n) {
			s[N - n] = h * w;
			return Arrays.stream(s).max().getAsLong() - Arrays.stream(s).min().getAsLong();
		}
		if ((0 == (h % n)) || (0 == (w % n))) {
			IntStream.range(N - n, N).forEach(i -> s[i] = h * w / n);
			return Arrays.stream(s).max().getAsLong() - Arrays.stream(s).min().getAsLong();
		} else {
			s[N - n] = h / n * w;
			long result1 = getResult(Math.max(h - h / n, w), Math.min(h - h / n, w), s, n - 1);
			s[N - n] = (h / n + 1) * w;
			long result2 = getResult(Math.max(h - h / n - 1, w), Math.min(h - h / n - 1, w), s, n - 1);
			return Math.min(result1, result2);
		}
	}
}
