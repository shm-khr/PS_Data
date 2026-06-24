import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//Light Road
public class Main{

	int[][] d = {{-1,0},{0,1},{1,0},{0,-1}};
	int[][] M = {
			{-1, 1, -2, 0},
			{1, -1, 0, -2},
			{-2, 0, -1, 1},
			{0, -2, 1, -1}
	};
	
	void run(){
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt(), w = sc.nextInt(), A = sc.nextInt();
		char[][] m = new char[h][];
		int si = -1, sj = -1;
		for(int i=0;i<h;i++){
			m[i] = sc.next().toCharArray();
			for(int j=0;j<w;j++)if(m[i][j]=='S'){
				si = i; sj = j;
			}
		}
		boolean[][][][][] u = new boolean[h][w][4][A+1][A+1];
		u[si][sj][2][0][0] = true;
		Queue<int[]> q = new LinkedList<int[]>();
		q.add(new int[]{si, sj, 2, 0, 0});
		int res = 100;
		while(!q.isEmpty()){
			int[] V = q.poll();
			int i = V[0], j = V[1], dir = V[2], P = V[3], Q = V[4];
			if(m[i][j]=='G'){
				res = Math.min(res, P+Q); continue;
			}
			for(int k=0;k<4;k++){
				int x = M[dir][k];
				if(x==-2)continue;
				int ni = i+d[k][0], nj = j+d[k][1];
				if(!(0<=ni&&ni<h&&0<=nj&&nj<w)||m[ni][nj]=='#'||m[ni][nj]=='S')continue;
				if(x==-1&&!u[ni][nj][k][P][Q]){
					u[ni][nj][k][P][Q] = true;  q.add(new int[]{ni, nj, k, P, Q});
				}
				else if(x==0&&m[i][j]=='.'&&P<A&&!u[ni][nj][k][P+1][Q]){
					u[ni][nj][k][P+1][Q] = true; q.add(new int[]{ni, nj, k, P+1, Q});
				}
				else if(x==1&&m[i][j]=='.'&&Q<A&&!u[ni][nj][k][P][Q+1]){
					u[ni][nj][k][P][Q+1] = true; q.add(new int[]{ni, nj, k, P, Q+1});
				}
			}
		}
		System.out.println(res==100?-1:res);
	}
	
	public static void main(String[] args) {
		new Main().run();
	}
}