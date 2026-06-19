
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}


	class Edge implements Comparable<Edge>{
		int from;
		int to;
		int cost;
		Edge(int from, int to, int cost){
			this.from=from;
			this.to=to;
			this.cost=cost;
		}
		@Override
		public int compareTo(Edge o) {
			return Integer.compare(this.cost, o.cost);
		}
	}

	class P{
		int id;
		int x;
		int y;
		P(int id, int x,int y){
			this.id=id;
			this.x=x;
			this.y=y;
		}
	}

	class FindSet{
		int n;
		int p[];
		int d[];
		FindSet(int n){
			this.n=n;
			p = new int[n];
			d = new int[n];
			for(int i=0; i<n; i++) {
				p[i]=i;
				d[i]=1;
			}
		}
		public int find(int x) {
			if(p[x] != x) {
				p[x] = find(p[x]);
			}
			return p[x];
		}
		public boolean same(int x, int y) {
			return find(x) == find(y);
		}
		public void join(int x,int y) {
			if(d[x] < d[y]) {
				p[x] = y;
			}else {
				p[y]=x;
				if(d[x]==d[y]) {
					d[x]++;
				}
			}
		}
		public void unite(int x, int y) {
			if(same(x,y)) return;
			join(find(x), find(y));
		}
	}
	public void run() {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		ArrayList<P> pl = new ArrayList<>();
		ArrayList<Edge> el = new ArrayList<>();
		for(int i=0; i<n; i++) {
			int id = i;
			int x = sc.nextInt();
			int y = sc.nextInt();
			pl.add(new P(id, x, y));
		}

		//x座標でソード
		pl.sort((o1, o2)->Integer.compare(o1.x, o2.x));
		for(int i=1; i<pl.size(); i++) {
			P from = pl.get(i-1);
			P to = pl.get(i);
			el.add(new Edge(from.id, to.id, to.x-from.x));
		}
		//y座標でソート
		pl.sort((o1, o2)->Integer.compare(o1.y, o2.y));
		for(int i=1; i<pl.size(); i++) {
			P from = pl.get(i-1);
			P to = pl.get(i);
			el.add(new Edge(from.id, to.id, to.y-from.y));
		}
		//costでソート
		Collections.sort(el);

		FindSet fs = new FindSet(n);
		long ans = 0;
		for(int i=0; i<el.size(); i++) {
			Edge e = el.get(i);
			if(!fs.same(e.from, e.to)) {
				fs.unite(e.from, e.to);
				ans += e.cost;
			}
		}
		System.out.println(ans);
		sc.close();
	}

}
