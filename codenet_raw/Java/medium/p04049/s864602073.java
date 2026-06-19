import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main{
	static int n,k;
	static LinkedList<Integer>[] g;
	//頂点xを中心としたときに削除する頂点の個数を返す関数
	static int cal(int x){
		int[] ans=bfs(x);
		int res=0;
		for(int i=0;i<n;i++) if(2*ans[i]>k) res++;
		return res;
	}
	static int[] bfs(int x){
		int[] res=new int[n];
		Arrays.fill(res,-1);
		Queue<state> que=new ArrayDeque<state>();
		que.add(new state(x,-1));
		res[x]=0;
		while(!que.isEmpty()){
			state now=que.poll();
			for(int e:g[now.x]){
				if(e!=now.p && res[e]==-1){
					res[e]=res[now.x]+1;
					que.add(new state(e,now.x));
				}
			}
		}
		return res;
	}
	static class state{
		int x,p;
		public state(int a,int b){
			x=a; p=b;
		}
	}
	@SuppressWarnings("unchecked")
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			n=sc.nextInt();
			k=sc.nextInt();
			g=new LinkedList[n]; for(int i=0;i<n;i++) g[i]=new LinkedList<Integer>();
			for(int i=0;i<n-1;i++){
				int a=sc.nextInt(); a--;
				int b=sc.nextInt(); b--;
				g[a].add(b);
				g[b].add(a);
			}
			int min=Integer.MAX_VALUE;
			for(int i=0;i<n;i++) min=Math.min(min,cal(i));
			System.out.println(min);
		}
	}
}