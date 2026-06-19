import java.io.*;
import java.util.*;

public class Main{
	static long INF=(long)1e16;
	static LinkedList<Edge>[]adjList;
	static long[] dijkstra(int s,int n)	//O(E log E)
	{
		long[] d = new long[n];
		Arrays.fill(d, INF);
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
		d[cities[s]] = 0;
		pq.add(new Edge(cities[s], 0));						//may add more in case of MSSP (Mult-Source)
		while(!pq.isEmpty())
		{
			Edge cur = pq.remove();
			if(cur.cost > d[cur.node])			//lazy deletion
				continue;
			for(Edge nxt: adjList[cur.node])
				if(cur.cost + nxt.cost < d[nxt.node]) {
					pq.add(new Edge(nxt.node, d[nxt.node] = cur.cost + nxt.cost ));
				}
		}
		return d;
	}
	static class Edge implements Comparable<Edge>{
    	int node;
    	long cost;
    	Edge(int a,long b){
    		node=a;cost=b;
    	}
		@Override
		public int compareTo(Edge o) {
			if(cost!=o.cost) {
				return Long.compare(cost, o.cost);
			}
				return node-o.node;
			
		}
		public String toString() {
			return "("+node+" "+cost+")";
		}
    }
	static int[]cities;
	static long[][]dist,pathes;
	static int mod=(int)1e9+7;
	static long dp(int city,int i) {
		if(pathes[city][i]!=-1)return pathes[city][i];
		if(cities[city]==i)return pathes[city][i]=1;
		long ans=0;
		for(Edge e:adjList[i]) {
			int nxt=e.node;long cost=e.cost;
			if(dist[city][i]==dist[city][nxt]+cost) {
				ans+=dp(city, nxt);
				ans%=mod;
			}
		}
		return pathes[city][i]=ans;
	}
	static void main() throws Exception{
		int n=sc.nextInt(),m=sc.nextInt();
		cities=new int[] {sc.nextInt()-1,sc.nextInt()-1};
		adjList=new LinkedList[n];
		for(int i=0;i<n;i++)adjList[i]=new LinkedList<Edge>();
		for(int i=0;i<m;i++) {
			int x=sc.nextInt()-1,y=sc.nextInt()-1,d=sc.nextInt();
			adjList[x].add(new Edge(y, d));
			adjList[y].add(new Edge(x, d));
		}
		dist=new long[2][n];
		for(int i=0;i<2;i++) {
			dist[i]=dijkstra(i, n);
		}
		pathes=new long[2][n];
		for(int i=0;i<2;i++)Arrays.fill(pathes[i], -1);
		for(int i=0;i<2;i++) {
			for(int j=0;j<n;j++) {
				dp(i, j);
			}
		}
		long allPathes=pathes[0][cities[1]];
		long ans=(allPathes*allPathes)%mod;
		
		long bad=0;
		long pathDist=dist[0][cities[1]];
		for(int i=0;i<n;i++) {
			//if i lies in the middle of some path from s to t
			if(dist[0][i]*2==pathDist) {
				//pathes that pass by i
				long cnt=(pathes[0][i]*pathes[1][i])%mod;
				bad+=((cnt*cnt)%mod);
				bad%=mod;
			}
		}
		for(int i=0;i<n;i++) {
			for(Edge e:adjList[i]) {
				int nxt=e.node;long cost=e.cost;
				if(dist[0][i]!=dist[0][nxt]+cost || cost+dist[1][i]+dist[0][nxt]!=pathDist)continue;
				//if i and nxt lie in the middle of some path from s to t
				if(dist[0][i]*2>pathDist && dist[0][nxt]*2<pathDist) {
					//pathes that pass by i and nxt
					long cnt=(pathes[1][i]*pathes[0][nxt])%mod;
					bad+=((cnt*cnt)%mod);
					bad%=mod;
				}
			}
		}
		pw.println((ans-bad+mod)%mod);
	}
	public static void main(String[] args) throws Exception{
		sc=new MScanner(System.in);
		pw = new PrintWriter(System.out);
		int tc=1;
//		tc=sc.nextInt();
		while(tc-->0)
			main();
		pw.flush();
	}
	static PrintWriter pw;
	static MScanner  sc;
	static class MScanner {
		StringTokenizer st;
		BufferedReader br;
		public MScanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}
 
		public MScanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public int[] intArr(int n) throws IOException {
	        int[]in=new int[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public long[] longArr(int n) throws IOException {
	        long[]in=new long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public int[] intSortedArr(int n) throws IOException {
	        int[]in=new int[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        shuffle(in);
	        Arrays.sort(in);
	        return in;
		}
		public long[] longSortedArr(int n) throws IOException {
	        long[]in=new long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        shuffle(in);
	        Arrays.sort(in);
	        return in;
		}
		public Integer[] IntegerArr(int n) throws IOException {
	        Integer[]in=new Integer[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public Long[] LongArr(int n) throws IOException {
	        Long[]in=new Long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public String nextLine() throws IOException {
			return br.readLine();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
 
		public char nextChar() throws IOException {
			return next().charAt(0);
		}
 
		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
	static void shuffle(int[]in) {
		for(int i=0;i<in.length;i++) {
			int idx=(int)(Math.random()*in.length);
			int tmp=in[i];
			in[i]=in[idx];
			in[idx]=tmp;
		}
	}
	static void shuffle(long[]in) {
		for(int i=0;i<in.length;i++) {
			int idx=(int)(Math.random()*in.length);
			long tmp=in[i];
			in[i]=in[idx];
			in[idx]=tmp;
		}
	}
}