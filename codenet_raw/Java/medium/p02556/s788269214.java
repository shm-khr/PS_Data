
import java.util.*;
import java.math.*;

class Main {
	static Scanner sc = new Scanner(System.in);

	void solve() {
		try {
			int n = sc.nextInt();
			ArrayList<Integer> a = new ArrayList<>();
			ArrayList<Integer> b = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				a.add(sc.nextInt());
				b.add(sc.nextInt());
			}

			int r1 = Math.abs((Collections.max(b) - Collections.min(b)))
					+ Math.abs(a.get(b.indexOf(Collections.max(b))) - a.get(b.indexOf(Collections.min(b))));
			int r2 = Math.abs((Collections.max(a) - Collections.min(a)))
					+ Math.abs(b.get(a.indexOf(Collections.max(a))) - b.get(a.indexOf(Collections.min(a))));
			System.out.println(Math.max(r1, r2));
		} catch (Exception e) {
			return;
		}
	}

	public static void main(String[] args) {
		Main ob = new Main();
		ob.solve();
	}
}