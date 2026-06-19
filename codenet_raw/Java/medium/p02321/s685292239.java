import java.util.Scanner;


public class Main{
	static int N;
	static long W;
	static long[] v=new long[41];
	static long[] w=new long[41];
	static long dfs(int cur, long ww, long vv) {
		long m=0;
		if(cur==N) {
			return vv;
		}
		for(int i=cur+1; i<=N; i++) {
			if(w[i]<=ww) {
				m=Math.max(m, dfs(i, ww-w[i], vv+v[i]));
			}
			else m=Math.max(m, vv);
		}
		return m;
	}
    public  static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
        	N=sc.nextInt();
        	W=sc.nextInt();
        	for(int i=1; i<=N; i++) {
        		v[i]=sc.nextInt();
        		w[i]=sc.nextInt();
        	}
        	System.out.println(dfs(0, W, 0));
        }
    }
}
