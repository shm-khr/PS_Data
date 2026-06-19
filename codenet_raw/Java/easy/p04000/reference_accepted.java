import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.IntStream;

/**
 * 解説通り実装したソースコード
 */
public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int h = scanner.nextInt(), w = scanner.nextInt(), n = scanner.nextInt();
			Map<String, Integer> map = new HashMap<>();
			IntStream.range(0, n).forEach(i -> {
				int a = scanner.nextInt(), b = scanner.nextInt();
				IntStream.rangeClosed(0, 2).filter(j -> (a - j > 0) && (a - j <= h - 2)).forEach(
						j -> IntStream.rangeClosed(0, 2).filter(k -> (b - k > 0) && (b - k <= w - 2)).forEach(k -> {
							String key = (a - j) + "_" + (b - k);
							map.put(key, map.getOrDefault(key, 0) + 1);
						}));
			});
			long[] results = new long[10];
			map.entrySet().stream().forEach(entry -> results[entry.getValue()]++);
			results[0] = (h - 2L) * (w - 2L) - map.size();
			Arrays.stream(results).forEach(System.out::println);
		}
	}
}
