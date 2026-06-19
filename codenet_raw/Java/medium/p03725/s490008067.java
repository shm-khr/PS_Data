import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Main main = new Main();
		main.solveC();
	}


	private void solveC() {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int K = sc.nextInt();
		sc.nextLine();
		int[][] dist_map = new int[H][];
		int start_r = -1;
		int start_c = -1;
		for (int r = 0; r < H; r++) {
			dist_map[r] = new int[W];
			String line = sc.nextLine();
			for (int c = 0; c < W; c++) {
				char panel = line.charAt(c);
				if (panel == 'S') {
					start_r = r;
					start_c = c;
					dist_map[r][c] = 1;
				} else if (panel == '#') {
					dist_map[r][c] = -1;
				} else {
					dist_map[r][c] = H * W * 2;
				}
			}
		}
		search(start_r, start_c, 0, dist_map, H, W, K);
		int min_dist = H + W;
		for (int r = 0; r < H; r++) {
			for (int c = 0; c < W; c++) {
				if (dist_map[r][c] <= K && dist_map[r][c] >= 0) {
					if (min_dist > r) {
						min_dist = r;
					}
					if (min_dist > c) {
						min_dist = c;
					}
					if (min_dist > H - 1 - r) {
						min_dist = H - 1 - r;
					}
					if (min_dist > W - 1 - c) {
						min_dist = W - 1 - c;
					}
				}
			}
		}
		if (min_dist == 0) {
			System.out.println(1);
		} else {
			System.out.println((min_dist - 1) / K + 2);
		}
	}

	private void search(int r, int c, int dist, int[][] map, int limit_r, int limit_c, int K) {
		if (dist > K || r < 0 || c < 0 || r >= limit_r || c >= limit_c) {
			return;
		}
		if (dist < map[r][c]) {
			map[r][c] = dist;
			search(r - 1, c, dist + 1, map, limit_r, limit_c, K);
			search(r, c - 1, dist + 1, map, limit_r, limit_c, K);
			search(r + 1, c, dist + 1, map, limit_r, limit_c, K);
			search(r, c + 1, dist + 1, map, limit_r, limit_c, K);
		}
	}
}