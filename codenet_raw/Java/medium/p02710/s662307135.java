import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
	static int n;
	static int[] c;
	static boolean[] exist;
	static long[] rem;
	static List<List<Integer>> list;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] sa = br.readLine().split(" ");
		n = Integer.parseInt(sa[0]);
		sa = br.readLine().split(" ");
		c = new int[n];
		exist = new boolean[n];
		for (int i = 0; i < n; i++) {
			int col = Integer.parseInt(sa[i]) - 1;
			c[i] = col;
			exist[col] = true;
		}

		list = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			list.add(new ArrayList<>());
		}
		for (int i = 0; i < n - 1; i++) {
			sa = br.readLine().split(" ");
			int a = Integer.parseInt(sa[0]) - 1;
			int b = Integer.parseInt(sa[1]) - 1;
			list.get(a).add(b);
			list.get(b).add(a);
		}
		br.close();

		rem = new long[n];
		Map<Integer, Integer> sub = dfs(0, -1);
		sub.remove(c[0]);
		for (Integer key : sub.keySet()) {
			long val = n - sub.get(key);
			rem[key] += val * (val + 1) / 2;
		}
		long total = (long) n * (n + 1) / 2;

		PrintWriter pw = new PrintWriter(System.out);
		for (int i = 0; i < n; i++) {
			if (exist[i]) {
				pw.println(total - rem[i]);
			} else {
				pw.println(0);
			}
		}
		pw.flush();
	}

	static Map<Integer, Integer> dfs(int x, int p) {
		int size = 0;
		Map<Integer, Integer> ret = new HashMap<>();
		for (int next : list.get(x)) {
			if (next != p) {
				Map<Integer, Integer> sub = dfs(next, x);
				int total = sub.get(c[next]);
				Integer ng = sub.remove(c[x]);
				if (ng == null) {
					ng = 0;
				}
				long val = total - ng;
				rem[c[x]] += val * (val + 1) / 2;

				size += total;
				for (Integer key : sub.keySet()) {
					if (ret.containsKey(key)) {
						ret.put(key, ret.get(key) + sub.get(key));
					} else {
						ret.put(key, sub.get(key));
					}
				}
			}
		}

		size++;
		ret.put(c[x], size);
		return ret;
	}
}
