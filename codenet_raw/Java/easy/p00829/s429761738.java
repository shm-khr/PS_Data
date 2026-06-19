import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int S = sc.nextInt();
		for (int j = 0; j < S; ++j) {
			long[] input = new long[9];
			for (int i = 0; i < 9; ++i) {
				// 10進数に変換しておく
				input[i] = Long.parseLong(sc.next(), 16);
				System.out.println(Long.toString(input[i], 2).toLowerCase());
			}

			long key = 0;
			for (int i = 0; i < 32; ++i) {
				long sum = 0;
				for (int q = 0; q < 8; ++q) {
					sum += input[q] ^ key;
				}

				if ((sum & (1L << (i + 1) - 1)) != ((input[8] ^ key) & (1L << (i + 1) - 1))) {
					// keyの後ろからi桁目を0として計算した時に、sumとinput[8]の下i桁が等しくならなかった場合、
					// keyのi桁目を1にする
					key |= (1L << i);
				}
			}
			System.out.println(Long.toString(key, 2).toLowerCase());
		}

		sc.close();
	}
}