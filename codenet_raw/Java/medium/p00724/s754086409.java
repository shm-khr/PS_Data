
import java.util.*;
import java.io.*;

import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Math.*;

public class Main {

	int INF = 1 << 28;
	//long INF = 1L << 62;
	double EPS = 1e-10;

	int[] dx = {0,1,1,0,-1,-1,0};
	int[] dy = {-1,-1,0,1,1,0,0};

	int n, k, X, Y;
	P[] stn;

	void run() {
		Scanner sc = new Scanner(System.in);
		Bodies[] bodies = new Bodies[9];

		for (int len=2;len<9;len++) {
			bodies[len] = new Bodies();
			make_next_body(bodies[len], len);
		}
/*
		for (int len=2;len<9;len++) for (Map.Entry<String, NextBody> entry : bodies[len].entrySet()) {
			debug(entry.getKey());
			for (Snake s : entry.getValue()) {
				debug(s.head.x, s.head.y, s.body);
			}
		}*/

		for (;;) {
			n = sc.nextInt();
			if (n == 0) break;

			P[] ps = new P[n];
			for (int i=0;i<n;i++)
				ps[i] = new P(sc.nextInt(), sc.nextInt());

			k = sc.nextInt();
			stn = new P[k];
			for (int i=0;i<k;i++)
				stn[i] = new P(sc.nextInt(), sc.nextInt());

			X = sc.nextInt(); Y = sc.nextInt();

			Snake s = new Snake(ps);
			System.out.println(bfs(s, bodies));
		}
	}

	int bfs(Snake s, Bodies[] bodies) {
		PriorityQueue<Snake> q = new PriorityQueue<Snake>();
		HashSet<Snake> visited = new HashSet<Snake>();
		q.add(s); visited.add(s);

		for (;! q.isEmpty();) {
			Snake cur = q.remove();
			if (cur.head.x == X && cur.head.y == Y)
				return cur.c;

			for (Snake tmp : bodies[n].get(cur.body)) {
				Snake next = new Snake(new P(cur.head.x + tmp.head.x, cur.head.y + tmp.head.y), tmp.body, cur.c + 1);
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
		P p = new P(s.head.x, s.head.y);
		for (int j=0;j<k;j++){
			if (p.equals(stn[j])) return true;
		}

		for (int i=0;i<n-1;i++) {
			p.x += dx[s.body.charAt(i) - '0'];
			p.y += dy[s.body.charAt(i) - '0'];

			for (int j=0;j<k;j++){
				if (p.equals(stn[j])) return true;
			}
		}
		return false;
	}

	StringBuffer sb;
	void make_next_body(Bodies bodies, int len) {
//		debug(len);
		HashSet<String> body = new HashSet<String>();
		sb = new StringBuffer("");
		make_body(0, len, body);
//debug(body);
		for (String s : body) {
			NextBody next = new NextBody();
			for (String t : body) for (int d=0;d<7;d++){
				if (is_next_body(s, t, d)) {
					Snake next_snake = new Snake(new P(dx[d], dy[d]), t, 0);
					next.add(next_snake);
				}
			}
			bodies.put(s, next);
		}
	}

	void make_body(int p, int len, HashSet<String> body) {
		if (p == len-1) {
			if (is_boady(sb.toString()))
				body.add(sb.toString());
			return;
		}

		for (int i=0;i<6;i++) {
			sb.append(i);
			make_body(p+1, len, body);
			sb.deleteCharAt(p);
		}
	}

	boolean is_boady(String body) {
//if (body.equalsIgnoreCase("34")) debug();
		HashSet<P> ps = new HashSet<P>();
		ps.add(new P(0, 0));
		int cx = 0, cy = 0;
		for (int i=0;i<body.length();i++) {
			cx += dx[body.charAt(i) - '0'];
			cy += dy[body.charAt(i) - '0'];
//if (body.equalsIgnoreCase("34")) debug("begin");

			if (ps.contains(new P(cx, cy))) return false;

			int cnt = 0;
			for (P p : ps) if (connect(p, new P(cx, cy))) cnt++;
//if (body.equalsIgnoreCase("34")) debug(cx, cy, ps, cnt);

			if (cnt != 1) return false;
			ps.add(new P(cx, cy));
		}
		return true;
	}

	boolean is_next_body(String s, String t, int d) {
		P[] ps = new P[s.length()+1], pt = new P[s.length()+1];
		ps[0] = new P(0, 0);
		pt[0] = new P(ps[0].x+dx[d], ps[0].y+dy[d]);
		boolean f = true;
		boolean same = ps[0].equals(pt[0]);
		for (int i=0;i<s.length();i++) {
			ps[i+1] = new P(ps[i].x+dx[s.charAt(i) - '0'], ps[i].y + dy[s.charAt(i) - '0']);
			pt[i+1] = new P(pt[i].x+dx[t.charAt(i) - '0'], pt[i].y + dy[t.charAt(i) - '0']);

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

	class Bodies extends HashMap<String, NextBody> {}

	class NextBody extends HashSet<Snake> {}

	class Snake implements Comparable<Snake>{
		P head;
		String body;
		int c;
		Snake(P head, String body, int c) {
			this.head = new P(head.x, head.y);
			this.body = body;
			this.c = c;
		}

		Snake(P[] ps) {
			head = new P(ps[0].x, ps[0].y);
			body = "";
			for (int i=1;i<n;i++) {
				body += dir(ps[i-1], ps[i]);
			}
			c = 0;
		}

		@Override
		public int compareTo(Snake o) {
			// TODO 自動生成されたメソッド・スタブ
			if (c != o.c) return c - o.c;
			return abs(head.x) + abs(head.y) - abs(o.head.x) - abs(o.head.y);
		}

		public boolean equals(Object o) {
			if (o instanceof Snake) {
				Snake snk = (Snake) o;
				if (head.equals(snk.head) && body.equalsIgnoreCase(snk.body))
					return true;
			}
			return false;
		}

		public int hashCode() {
			return head.hashCode() + body.hashCode();
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