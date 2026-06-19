package ALDS1_12_B;

import java.util.Scanner;

public class Main {
	static int[][] W;
	static int[] distance;
	static boolean[] state;
	static int INF = 200000;

	public static void main(String[] args) {
		Scanner sr = new Scanner(System.in);
		int N = sr.nextInt();
		distance = new int[N];
		state = new boolean[N];
		W = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				W[i][j] = INF;
			}
			distance[i] = INF;
			state[i] = true;
		}
		for (int i = 0; i < N; i++) {
			int sub = sr.nextInt();
			int k = sr.nextInt();
			for (int j = 0; j < k; j++) {
				int v = sr.nextInt();
				int c = sr.nextInt();
				W[i][v] = c;
			}
		}
		int k = 0;
		distance[0] = 0;

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {
				int min = INF;
				if (min > distance[j] && state[j] == true) {
					min = distance[j];
					k = j;
				}
			}
			state[k] = false;

			for(int x = 0; x < N; x++) {
				int min2 = distance[k] + W[k][x];

				if(distance[x] < distance[k] + W[k][x]) {
					min2 = distance[x];
				}
				distance[x] = min2;

			}

		}

		for(int i = 0; i < N; i++) {
			System.out.println(i + " " + distance[i]);
		}

		sr.close();
	}
}

