import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
	static int[] parents;
	static int[] weight;
	static int[] rank;

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int n = scanner.nextInt();
		int q = scanner.nextInt();

		parents = new int[n];
		weight = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parents[i] = i;
		}

		int type, x, y, z;
		for (int i = 0; i < q; i++) {
			type = scanner.nextInt();
			x = scanner.nextInt();
			y = scanner.nextInt();

			if(type == 0) {
				z = scanner.nextInt();
				relate(x, y, z);
			} else {
				diff(x, y);
			}
		}
	}

	static int find(int x) {
		if (x == parents[x]) 
			return x;
		else {
			int r = find(parents[x]);
			weight[x] += weight[parents[x]];
			return parents[x] = r;
		}
	}

	static int weight(int x) {
		find(x);
		return weight[x];
	}

	static void relate(int x, int y, int z) {
		z += weight(x);
		z -= weight(y);
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(rank[x] < rank[y]){
			int tmp = x;
			x = y;
			y = tmp;
			z = -z;
		}

		if(rank[x] == rank[y]){
			rank[x]++;
		}

		parents[y] = x;
		weight[y] = z;
	}

	static void diff(int x, int y) {
		if(find(x) == find(y)) {
			System.out.println(weight(y) - weight(x));
		} else {
			System.out.println("?");
		}
	}
}
