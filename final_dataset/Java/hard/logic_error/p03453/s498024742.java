import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	
	public static class State implements Comparable<State> {
		int node;
		long time;
		
		public State(int node, long time){
			this.node = node;
			this.time = time;
		}

		@Override
		public int compareTo(State o) {
			return Long.compare(this.time, o.time);
		}
	}
	
	public static final long MOD = 1000000007;
	
	public static void dijkstra(final int N, int start, long[] times, long[] patterns, ArrayList<HashMap<Integer, Long>> adj){
		PriorityQueue<State> queue = new PriorityQueue<State>();
		
		Arrays.fill(times, Long.MAX_VALUE);
		Arrays.fill(patterns, 0);
		
		times[start] = 0;
		patterns[start] = 1;
		queue.add(new State(start, 0));
		
		while(!queue.isEmpty()){
			final State state = queue.poll();
			final int node = state.node;
			final long time = state.time;
			
			if(times[node] < state.time){ continue; }
			
			for(final Entry<Integer, Long> entry : adj.get(node).entrySet()){
				final int next = entry.getKey();
				final long next_time = time + entry.getValue();
				
				if(times[next] < next_time){ continue; }
				
				if(times[next] > next_time){
					times[next] = next_time;
					patterns[next] = patterns[node];
					
					queue.add(new State(next, next_time));
				}else{
					patterns[next] += patterns[node];
					patterns[next] %= MOD;
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		
		final int N = sc.nextInt();
		final int M = sc.nextInt();
		final int S = sc.nextInt() - 1;
		final int T = sc.nextInt() - 1;
		
		ArrayList<HashMap<Integer, Long>> adj = new ArrayList<HashMap<Integer, Long>>();
		ArrayList<HashSet<Integer>> bridges = new ArrayList<HashSet<Integer>>();
		for(int i = 0; i < N; i++){ adj.add(new HashMap<Integer, Long>()); }
		for(int i = 0; i < N; i++){ bridges.add(new HashSet<Integer>()); }
		
		for(int i = 0; i < M; i++){
			final int U = sc.nextInt() - 1;
			final int V = sc.nextInt() - 1;
			final long D = sc.nextLong();
			
			adj.get(U).put(V, D);
			adj.get(V).put(U, D);
		}
		
		long[] from_S_times = new long[N];
		long[] from_S_patterns = new long[N];
		long[] from_T_times = new long[N];
		long[] from_T_patterns = new long[N];
		
		dijkstra(N, S, from_S_times, from_S_patterns, adj);
		dijkstra(N, T, from_T_times, from_T_patterns, adj);
		
		//System.out.println(from_S_patterns[T] + " " + from_T_patterns[S]);
		//System.out.println(Arrays.toString(from_S_times));
		
		long answer = (from_S_patterns[T] * from_T_patterns[S]) % MOD;
		//System.out.println(answer);
		
		// 同時に同じ頂点に到着する組み合わせは無視する
		//*
		for(int node = 0; node < N; node++){
			if(from_S_times[node] == from_T_times[node]){
				final long dup = (from_S_patterns[node] * from_T_patterns[node]) % MOD;
				final long dup2 = (dup * dup) % MOD;
				answer = (MOD + answer - dup2) % MOD;
			}
		}
		//*/
		
		// 辺でぶつかる組み合わせを除去する
		for(int node = 0; node < N; node++){
			for(final Entry<Integer, Long> entry : adj.get(node).entrySet()){
				final int next = entry.getKey();
				final long cost = entry.getValue();
				
				final long S_diff = from_S_times[next] - from_S_times[node];
				final long T_diff = from_T_times[node] - from_T_times[next];
				if(S_diff != cost || T_diff != cost){ continue; }
				
				if(from_S_times[next] <= from_T_times[next]){ continue; }
				if(from_S_times[node] >= from_T_times[node]){ continue; }
				
				final long dup = (from_S_patterns[node] * from_T_patterns[next]) % MOD;
				final long dup2 = (dup * dup) % MOD;
				//System.out.println(node + " " + next + " " + dup);
				answer = (MOD + answer - dup2) % MOD;
			}
		}
		
		/*
		System.out.println(from_S_used_edge);		
		System.out.println(from_S_times[T] + " : " + Arrays.toString(from_S_times));
		System.out.println(from_T_times[S] + " : " + Arrays.toString(from_T_times));
		*/
		System.out.println(answer);
	}
	
	public static class Scanner implements Closeable {
		private BufferedReader br;
		private StringTokenizer tok;
 
		public Scanner(InputStream is) throws IOException {
			br = new BufferedReader(new InputStreamReader(is));
		}	
 
		private void getLine() throws IOException {
			while (!hasNext()) {
				tok = new StringTokenizer(br.readLine());
			}
		}
 
		private boolean hasNext() {
			return tok != null && tok.hasMoreTokens();
		}
 
		public String next() throws IOException {
			getLine();
			return tok.nextToken();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
 
		public void close() throws IOException {
			br.close();
		}
	}
}