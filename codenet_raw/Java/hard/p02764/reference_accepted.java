import java.util.*;

class Main {
	Scanner sc;
	int N, K;
	int[] x, y, c;
	static final double eps = 1e-7;
	
	void calc() {
		sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		
		x = new int[N];
		y = new int[N];
		c = new int[N];
		for (int i = 0; i < N; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		
		double r = 2000d * Math.sqrt(2) * 100;
		double l = 0d;
		double m = 0;
		while (Math.abs(r-l)/r > eps) {
			m = (l + r) / 2;
			if (!Kintersects(m)) l = m;
			else r = m;
		}
		System.out.println(m);
	}
	
	private boolean Kintersects(double t) {
		for (int i = 0; i < N; i++) {
			if (Kcontains(t, x[i], y[i])) return true;
		}
		for (int i = 0; i < N-1; i++) {
			for (int j = i+1; j < N; j++) {
				double x2, y2, r1, r2, b, a, d, xa, ya;
				x2 = x[j] - x[i];
				y2 = y[j] - y[i];
				r1 = t/c[i];
				r2 = t/c[j];
				b = x2*x2 + y2*y2;
				a = (b + r1*r1 - r2*r2) / 2;
				d = b*r1*r1 - a*a;
				if (d < 0) continue;
				d = Math.sqrt(d);
				xa = (a*x2 + y2*d)/b + x[i];
				ya = (a*y2 - x2*d)/b + y[i];
				if (Kcontains(t, xa, ya)) return true;
				xa = (a*x2 - y2*d)/b + x[i];
				ya = (a*y2 + x2*d)/b + y[i];
				if (Kcontains(t, xa, ya)) return true;
			}
		}
		return false;
	}

	private boolean Kcontains(double t, double x, double y) {
		int c = 0;
		for (int i = 0; i < N; i++) {
			if (contains(i, t, x, y))
				if ( ++c >= K ) return true;
		}
		return false;
	}
	
	private boolean contains(int j, double t, double x, double y) {
		double xs, ys, d;
		xs = this.x[j] - x;
		ys = this.y[j] - y;
		d = Math.sqrt( xs*xs + ys*ys );
		return (d <= t/c[j]*(1+eps));
	}
	
	public static void main(String[] args) {
		new Main().calc();
	}
}
