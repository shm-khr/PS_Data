
import java.util.*;
import java.io.*;

import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Math.*;

public class Main {

	int INF = 1 << 28;
	//long INF = 1L << 62;
	double EPS = 1e-10;
	int LEN = 9;

	int[] dx = {0,1,1,0,-1,-1,0};
	int[] dy = {-1,-1,0,1,1,0,0};

	int n, k, X, Y;
	HashSet<P> stn;
	Bodies[] bodies;

	void run() {
		Scanner sc = new Scanner(System.in);
		bodies = new Bodies[9];

		for (int len=2;len<LEN;len++) {
			bodies[len] = new Bodies();
			make_next_body(len);
		}
//		debug(Runtime.getRuntime().totalMemory() / 1024);
//		for (int len=2;len<LEN;len++) debug(bodies[len].size()*(len-1));

/*		for (int len=2;len<LEN;len++) for (Map.Entry<Integer, NextBody> entry : bodies[len].entrySet()) {
			debug(entry.getKey());
			for (Snake s : entry.getValue()) {
				debug(s.x, s.y, Integer.toBinaryString(s.body));
			}
		}*/

		for (;;) {
			n = sc.nextInt();
			if (n == 0) break;

			P[] ps = new P[n];
			for (int i=0;i<n;i++)
				ps[i] = new P(sc.nextInt(), sc.nextInt());

			k = sc.nextInt();
			stn = new HashSet<P>();
			for (int i=0;i<k;i++)
				stn.add(new P(sc.nextInt(), sc.nextInt()));

			X = sc.nextInt(); Y = sc.nextInt();

			Snake s = new Snake(ps);
			System.out.println(bfs(s));
		}
	}

	int bfs(Snake s) {
		PriorityQueue<Snake> q = new PriorityQueue<Snake>();
		HashSet<Snake> visited = new HashSet<Snake>();
		q.add(s); visited.add(s);

		for (;! q.isEmpty();) {
			Snake cur = q.remove();
			if (cur.x == X && cur.y == Y)
				return cur.c;
//debug(Integer.toBinaryString(cur.body));
			for (Snake tmp : bodies[n].get(cur.body)) {
				Snake next = new Snake(cur.x + tmp.x, cur.y + tmp.y, tmp.body, cur.c + 1);
				if (hit(next)) continue;
				if (! visited.contains(next)) {
					visited.add(next);
					q.add(next);
				}
			}
		}
		return -1;
	}

	boolean hit(Snake s) {
		P p = new P(s.x, s.y);
		if (stn.contains(p)) return true;

		for (int i=0;i<n-1;i++) {
			p.x += dx[(s.body>>(i*3))&7];
			p.y += dy[(s.body>>(i*3))&7];

			for (int j=0;j<k;j++){
				if (stn.contains(p)) return true;
			}
		}
		return false;
	}

	int sb;
	HashSet<Integer> body;
	void make_next_body(int len) {
		body = new HashSet<Integer>();
		sb = 0;
		make_body(0, len);
		for (int s : body) {
			NextBody next = new NextBody();
			for (int t : body) for (int d=0;d<7;d++){
				if (is_next_body(s, t, d, len)) {
					Snake next_snake = new Snake(dx[d], dy[d], t, 0);
					next.add(next_snake);
				}
			}
			bodies[len].put(s, next);
		}
	}

	void make_body(int p, int len) {
		if (p == len-1) {
			if (is_body(sb, len))
				body.add(sb);
			return;
		}

		for (int i=0;i<6;i++) {
			sb |= i<<(p*3);
			make_body(p+1, len);
			sb &= (1<<(p*3))-1;
		}
	}

	boolean is_body(int body, int len) {
		HashSet<P> ps = new HashSet<P>();
		ps.add(new P(0, 0));
		int cx = 0, cy = 0;
		for (int i=0;i<len-1;i++) {
			cx += dx[(body>>(i*3))&7];
			cy += dy[(body>>(i*3))&7];

			if (ps.contains(new P(cx, cy))) return false;

			int cnt = 0;
			for (P p : ps) if (connect(p, new P(cx, cy))) cnt++;

			if (cnt != 1) return false;
			ps.add(new P(cx, cy));
		}
		return true;
	}

	boolean is_next_body(int s, int t, int d, int len) {
		P[] ps = new P[len], pt = new P[len];
		ps[0] = new P(0, 0);
		pt[0] = new P(ps[0].x+dx[d], ps[0].y+dy[d]);
		boolean f = true;
		boolean same = ps[0].equals(pt[0]);
		for (int i=0;i<len-1;i++) {
			ps[i+1] = new P(ps[i].x+dx[(s>>(i*3))&7], ps[i].y + dy[(s>>(i*3))&7]);
			pt[i+1] = new P(pt[i].x+dx[(t>>(i*3))&7], pt[i].y + dy[(t>>(i*3))&7]);

			if (! ps[i+1].equals(pt[i+1])) {
				same = false;
				if (! ps[i].equals(pt[i])) {
					f = false; break;
				}
				if (! connect(ps[i+1], pt[i+1])) {
					f = false; break;
				}
			}
		}

		if (f && ! same) {
			return true;
		}

		return false;
	}

	boolean connect(P s, P t) {
		for (int i=0;i<6;i++) {
			if (s.x == t.x + dx[i] && s.y == t.y + dy[i]) return true;
		}
		return false;
	}

	class Bodies extends HashMap<Integer, NextBody> {}

	class NextBody extends HashSet<Snake> {}

	class Snake implements Comparable<Snake>{
		int body;
		int c, x, y;
		Snake(int x, int y, int body, int c) {
			this.x = x;
			this.y = y;
			this.body = body;
			this.c = c;
		}

		Snake(P[] ps) {
			this.x = ps[0].x;
			this.y = ps[0].y;
			body = 0;
			for (int i=0;i<n-1;i++) {
				body |= ( dir(ps[i], ps[i+1]) << (i*3));
			}
			c = 0;
		}

		@Override
		public int compareTo(Snake o) {
			// TODO 自動生成されたメソッド・スタブ
			if (c != o.c) return c - o.c;
			return abs(x) + abs(y) - abs(o.x) - abs(o.y);
		}

		public boolean equals(Object o) {
			if (o instanceof Snake) {
				Snake snk = (Snake) o;
				if (x == snk.x && y == snk.y && body == snk.body)
					return true;
			}
			return false;
		}

		public int hashCode() {
			return x * (int)1e7 + y + body;
		}
	}

	int dir(P s, P t) {
		for (int i=0;;i++) if (s.x + dx[i] == t.x && s.y + dy[i] == t.y)
			return i;
	}

	class P {
		int x, y;
		P(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public boolean equals(Object o) {
			if (o instanceof P) {
				P p = (P) o;
				return x == p.x && y == p.y;
			}
			return false;
		}

		public int hashCode() {
			return x * 1000000 + y;
		}

		public String toString() {
			return "[ " + x + ", " + y + " ]";
		}
	}

	void debug(Object... os) {
		System.err.println(Arrays.deepToString(os));
	}

	public static void main(String[] args) {
		new Main().run();
	}
}