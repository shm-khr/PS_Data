import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static int N;
	static int W[][], distance[], state[];
	static final int INF = 1000000000;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();

		W = new int[N][N];
		distance = new int[N];
		state = new int[N];

		Arrays.fill(W, INF);
		/*
		 * Arrasys.fill は配列の初期化がデキル便利メソッド
		 *  for (int i = 0; i < N; i++) {
		 *   for (int * j = 0; j < N; j++) {
		 *    W[i][j] = INF;
		 *   }
		 *  }
		 */

		for (int i = 0; i < N; i++) {
			sc.nextInt(); // u を読み飛ばし
			int k = sc.nextInt();
			for (int j = 0; j < k; j++) {
				int v = sc.nextInt();
				int c = sc.nextInt();
				W[i][v] = c;
			}
		}
		dijkstra(0);
		for (int i = 0; i < N; i++) {
			System.out.println(i + " " + distance[i]);
		}
	}

	private static int min(int a, int b) {
		if (a < b)
			return a;
		return b;
	}

	private static void dijkstra(int start) {
		Arrays.fill(distance, INF);
		Arrays.fill(state, 0);
		distance[start] = 0;

		int p = 0; // 確定頂点番号を保存する変数
		for (int step = 0; step < N; step++) {
			int minimum = INF;
			for (int x = 0; x < N; x++) {
				if (state[x] == 0 && distance[x] < minimum) {
					p = x;
					minimum = distance[x];
				}
			}
			if (minimum == INF) {
				System.err.println("Disconnected Graph!\n");
				System.exit(-1);
			}
			state[p] = 1;
			for (int x = 0; x < N; x++)
				distance[x] = min(distance[x], distance[p] + W[p][x]);
		}

	}
}

