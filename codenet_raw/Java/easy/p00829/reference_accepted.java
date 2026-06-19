import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int S = sc.nextInt();
		for (int i = 0; i < S; ++i) {
			System.out.println(Long.toString(solve(), 16).toLowerCase());
		}
	}

	static long solve() {
		long[] input = new long[9];
		for (int i = 0; i < 9; ++i) {
			input[i] = Long.parseLong(sc.next(), 16);
		}
		long key = 0;
		for (int i = 0; i < 32; ++i) {
			if (!match(input, key, (1L << (i + 1)) - 1)) {
				key |= (1L << i);
			}
		}
		return key;
	}

	static boolean match(long[] input, long key, long mask) {
		long sum = 0;
		for (int i = 0; i < 8; ++i) {
			sum += input[i] ^ key;
		}
		return (sum & mask) == ((input[8] ^ key) & mask);
	}

}