import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.TreeMap;

public class Main {
	static ContestScanner in;static Writer out;static StringBuilder sb=new StringBuilder();
	public static void main(String[] args)
	{try{in=new ContestScanner();out=new Writer();Main solve=new Main();solve.solve();
	in.close();out.flush();out.close();}catch(IOException e){e.printStackTrace();}}
	static void dump(int[]a){sb.setLength(0);for(int i=0;i<a.length;i++)
	sb.append(a[i]).append("\t");out.println(sb.toString().trim());}
	static void dump(int[]a,int n){for(int i=0;i<a.length;i++)out.printf("%"+n+"d ",a[i]);out.println();}
	static void dump(long[]a){for(int i=0;i<a.length;i++)out.print(a[i]+" ");out.println();}
	static long pow(long a,int n){long r=1;while(n>0){if((n&1)==1)r*=a;a*=a;n>>=1;}return r;}
	static String itob(int a,int l){return String.format("%"+l+"s",Integer.toBinaryString(a)).replace(' ','0');}
	static void sort(int[]a){m_sort(a,0,a.length,new int[a.length]);}
	static void sort(int[]a,int l){m_sort(a,0,l,new int[l]);}
	static void sort(int[]a,int l,int[]buf){m_sort(a,0,l,buf);}
	static void sort(int[]a,int s,int l,int[]buf){m_sort(a,s,l,buf);}
	static void m_sort(int[]a,int s,int sz,int[]b)
	{if(sz<7){for(int i=s;i<s+sz;i++)for(int j=i;j>s&&a[j-1]>a[j];j--)swap(a, j, j-1);return;}
	m_sort(a,s,sz/2,b);m_sort(a,s+sz/2,sz-sz/2,b);int x=s;int l=s,r=s+sz/2;final int le=s+sz/2,re=s+sz;
	while(l<le&&r<re){if(a[l]>a[r])b[x++]=a[r++];else b[x++]=a[l++];}
	while(r<re)b[x++]=a[r++];while(l<le)b[x++]=a[l++];for(int i=s;i<s+sz;i++)a[i]=b[i];
	} /* qsort(3.5s)<<msort(9.5s)<<<shuffle+qsort(17s)<Arrays.sort(Integer)(20s) */
	static void sort(long[]a){m_sort(a,0,a.length,new long[a.length]);}
	static void sort(long[]a,int l){m_sort(a,0,l,new long[l]);}
	static void sort(long[]a,int l,long[]buf){m_sort(a,0,l,buf);}
	static void sort(long[]a,int s,int l,long[]buf){m_sort(a,s,l,buf);}
	static void m_sort(long[]a,int s,int sz,long[]b)
	{if(sz<7){for(int i=s;i<s+sz;i++)for(int j=i;j>s&&a[j-1]>a[j];j--)swap(a, j, j-1);return;}
	m_sort(a,s,sz/2,b);m_sort(a,s+sz/2,sz-sz/2,b);int x=s;int l=s,r=s+sz/2;final int le=s+sz/2,re=s+sz;
	while(l<le&&r<re){if(a[l]>a[r])b[x++]=a[r++];else b[x++]=a[l++];}
	while(r<re)b[x++]=a[r++];while(l<le)b[x++]=a[l++];for(int i=s;i<s+sz;i++)a[i]=b[i];}
	static void swap(long[]a,int i,int j){final long t=a[i];a[i]=a[j];a[j]=t;}
	static void swap(int[]a,int i,int j){final int t=a[i];a[i]=a[j];a[j]=t;}
	static int binarySearchSmallerMax(int[]a,int v)// get maximum index which a[idx]<=v
	{int l=-1,r=a.length-1,s=0;while(l<=r){int m=(l+r)/2;if(a[m]>v)r=m-1;else{l=m+1;s=m;}}return s;}
	static int binarySearchSmallerMax(int[]a,int v,int l,int r)
	{int s=-1;while(l<=r){int m=(l+r)/2;if(a[m]>v)r=m-1;else{l=m+1;s=m;}}return s;}
	List<Integer>[]randomTree(int n,Random r){List<Integer>[]g=graph(n);
	for(int i=1;i<n;i++){int p=r.nextInt(i);g[p].add(i);g[i].add(p);}return g;}
	static List<Integer>[]graph(int n){List<Integer>[]g=new List[n];
	for(int i=0;i<n;i++)g[i]=new ArrayList<>();return g;}
	void solve() throws NumberFormatException, IOException{
		int n = in.nextInt();
		if(n>300) return;
		int[] a = new int[n];
		int[] b = new int[n];
		int[] diff = new int[n];
		for(int i=0; i<n; i++){
			a[i] = in.nextInt();
		}
		int plus = 0;
		int minus = 0;
		HashMap<Integer, Integer> map = new HashMap<>();
		int idx = 0;
		for(int i=0; i<n; i++){
			b[i] = in.nextInt();
			diff[i] = a[i]-b[i];
			if(diff[i]<0){
				minus++;
				map.put(i, idx++);
			}
			else if(diff[i]>0){
				plus++;
				map.put(i, idx++);
			}
		}
		MinCostFlow mc = new MinCostFlow(plus+minus+2, 10000);
		for(int i=0; i<n; i++){
			if(diff[i]<=0){
				if(diff[i]<0){
					mc.edge(map.get(i), plus+minus+1, -diff[i], 0);
				}
				continue;
			}
			mc.edge(plus+minus, map.get(i), diff[i], 0);
			for(int j=0; j<n; j++){
				if(diff[j]>=0) continue;
				mc.edge(map.get(i), map.get(j), -diff[j], Math.abs(i-j));
			}
		}
		System.out.println(mc.flow(plus+minus, plus+minus+1));
	}
	
}

class MinCostFlow{
	final int n;
	int f;
	List<Edge>[] node;
	@SuppressWarnings("unchecked")
	public MinCostFlow(int n, int f) {
		this.n = n;
		this.f = f;
		node = new List[n];
		for(int i=0; i<n; i++) node[i] = new ArrayList<>();
	}
	void edge(int from, int to, int cap, int cost){
		Edge e = new Edge(to, cap, cost);
		Edge r = new Edge(from, 0, -cost);
		e.rev = r;
		r.rev = e;
		node[from].add(e);
		node[to].add(r);
	}
	int flow(int s, int t){
		int[] h = new int[n];
		int[] dist = new int[n];
		int[] preV = new int[n];
		int[] preE = new int[n];
		final int inf = 10000;
		PriorityQueue<Pos> qu = new PriorityQueue<>();
		int res = 0;
		while(f>0){
			Arrays.fill(dist, inf);
			dist[s] = 0;
			qu.clear();
			qu.add(new Pos(s, 0));
			while(!qu.isEmpty()){
				Pos p = qu.poll();
				if(dist[p.v]<p.d) continue;
				final int sz = node[p.v].size();
				for(int i=0; i<sz; i++){
					Edge e = node[p.v].get(i);
					final int nd = e.cost+p.d + h[p.v]-h[e.to];
					if(e.cap>0 && nd < dist[e.to]){
						preV[e.to] = p.v;
						preE[e.to] = i;
						dist[e.to] = nd;
						qu.add(new Pos(e.to, nd));
					}
				}
			}
			if(dist[t]==inf) break;
			for(int i=0; i<n; i++) h[i] += dist[i];
			int minf = f;
			for(int i=t; i!=s; i=preV[i]){
				minf = Math.min(minf, node[preV[i]].get(preE[i]).cap);
			}
			f -= minf;
			res += minf*h[t];
			for(int i=t; i!=s; i=preV[i]){
				node[preV[i]].get(preE[i]).cap -= minf;
				node[preV[i]].get(preE[i]).rev.cap += minf;
			}
		}
		return res;
	}
}
class Pos implements Comparable<Pos>{
	int v, d;
	public Pos(int v, int d) {
		this.v = v;
		this.d = d;
	}
	@Override
	public int compareTo(Pos o) {
		return d-o.d;
	}
}

class Edge{
	int to, cost;
	int cap;
	Edge rev;
	Edge(int t, int c, int co){
		to = t;
		cap = c;
		cost = co;
	}
	void rev(Edge r){
		rev = r;
	}
}


class MultiSet<T> extends HashMap<T, Integer>{
	@Override public Integer get(Object key){return containsKey(key)?super.get(key):0;}
	public void add(T key,int v){put(key,get(key)+v);}
	public void add(T key){put(key,get(key)+1);}
	public void sub(T key){final int v=get(key);if(v==1)remove(key);else put(key,v-1);}
	public MultiSet<T> merge(MultiSet<T> set)
	{MultiSet<T>s,l;if(this.size()<set.size()){s=this;l=set;}else{s=set;l=this;}
	for(Entry<T,Integer>e:s.entrySet())l.add(e.getKey(),e.getValue());return l;}
}
class OrderedMultiSet<T> extends TreeMap<T, Integer>{
	@Override public Integer get(Object key){return containsKey(key)?super.get(key):0;}
	public void add(T key,int v){put(key,get(key)+v);}
	public void add(T key){put(key,get(key)+1);}
	public void sub(T key){final int v=get(key);if(v==1)remove(key);else put(key,v-1);}
	public OrderedMultiSet<T> merge(OrderedMultiSet<T> set)
	{OrderedMultiSet<T>s,l;if(this.size()<set.size()){s=this;l=set;}else{s=set;l=this;}
	while(!s.isEmpty()){l.add(s.firstEntry().getKey(),s.pollFirstEntry().getValue());}return l;}
}
class Pair implements Comparable<Pair>{
	int a,b;final int hash;Pair(int a,int b){this.a=a;this.b=b;hash=(a<<16|a>>16)^b;}
	public boolean equals(Object obj){Pair o=(Pair)(obj);return a==o.a&&b==o.b;}
	public int hashCode(){return hash;}
	public int compareTo(Pair o){if(a!=o.a)return a<o.a?-1:1;else if(b!=o.b)return b<o.b?-1:1;return 0;}
}
class Timer{
	long time;public void set(){time=System.currentTimeMillis();}
	public long stop(){return time=System.currentTimeMillis()-time;}
	public void print(){System.out.println("Time: "+(System.currentTimeMillis()-time)+"ms");}
	@Override public String toString(){return"Time: "+time+"ms";}
}
class Writer extends PrintWriter{
	public Writer(String filename)throws IOException
	{super(new BufferedWriter(new FileWriter(filename)));}
	public Writer()throws IOException{super(System.out);}
}
class ContestScanner implements Closeable{
	private BufferedReader in;private int c=-2;
	public ContestScanner()throws IOException 
	{in=new BufferedReader(new InputStreamReader(System.in));}
	public ContestScanner(String filename)throws IOException
	{in=new BufferedReader(new InputStreamReader(new FileInputStream(filename)));}
	public String nextToken()throws IOException {
		StringBuilder sb=new StringBuilder();
		while((c=in.read())!=-1&&Character.isWhitespace(c));
		while(c!=-1&&!Character.isWhitespace(c)){sb.append((char)c);c=in.read();}
		return sb.toString();
	}
	public String readLine()throws IOException{
		StringBuilder sb=new StringBuilder();if(c==-2)c=in.read();
		while(c!=-1&&c!='\n'&&c!='\r'){sb.append((char)c);c=in.read();}
		return sb.toString();
	}
	public long nextLong()throws IOException,NumberFormatException
	{return Long.parseLong(nextToken());}
	public int nextInt()throws NumberFormatException,IOException
	{return(int)nextLong();}
	public double nextDouble()throws NumberFormatException,IOException 
	{return Double.parseDouble(nextToken());}
	public void close() throws IOException {in.close();}
}