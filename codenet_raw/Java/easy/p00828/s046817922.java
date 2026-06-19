import java.util.*;
import static java.lang.System.*;

public class Main {

	Scanner sc = new Scanner(in);
	int[][][] board;
	int n,m;
	
	boolean isEnd(int x, int y, int z, int c) {
		if (z >= m) {
			boolean flag = true;
			for (int i = z; i >= z-m+1; i--) {
				if (board[x][y][i] != c) {
					flag = false;
					break;
				}
			}
			if (flag) return true;
		}
		int count1, count2, ix, iy, iz;
		
		count1 = count2 = 0;
		ix = x; iy = y;
		while (++ix < n && board[ix][iy][z] == c) count1++;
		ix = x; iy = y;
		while (--ix >= 0 && board[ix][iy][z] == c) count2++;
		if (count1+count2+1 >= m) return true;
		
		count1 = count2 = 0;
		ix = x; iy = y;
		while (++iy < n && board[ix][iy][z] == c) count1++;
		ix = x; iy = y;
		while (--iy >= 0 && board[ix][iy][z] == c) count2++;
		if (count1+count2+1 >= m) return true;
		
		count1 = count2 = 0;
		ix = x; iy = y;
		while (++ix < n && ++iy < n && board[ix][iy][z] == c) count1++;
		ix = x; iy = y;
		while (--ix >= 0 && --iy >= 0 && board[ix][iy][z] == c) count2++;
		if (count1+count2+1 >= m) return true;
		
		count1 = count2 = 0;
		iz = z; iy = y;
		while (++iz < n && ++iy < n && board[x][iy][iz] == c) count1++;
		iz = z; iy = y;
		while (--iz >= 0 && --iy >= 0 && board[x][iy][iz] == c) count2++;
		if (count1+count2+1 >= m) return true;
		
		count1 = count2 = 0;
		iz = z; ix = x;
		while (++iz < n && ++ix < n && board[ix][y][iz] == c) count1++;
		iz = z; ix = x;
		while (--iz >= 0 && --ix >= 0 && board[ix][y][iz] == c) count2++;
		if (count1+count2+1 >= m) return true;
		
		count1 = count2 = 0;
		ix = x; iy = y;
		while (++ix < n && --iy >= 0 && board[ix][iy][z] == c) count1++;
		ix = x; iy = y;
		while (--ix >= 0 && ++iy < n && board[ix][iy][z] == c) count2++;
		if (count1+count2+1 >= m) return true;
		
		count1 = count2 = 0;
		iz = z; iy = y;
		while (++iz < n && --iy >= 0 && board[x][iy][iz] == c) count1++;
		iz = z; iy = y;
		while (--iz >= 0 && ++iy < n && board[x][iy][iz] == c) count2++;
		if (count1+count2+1 >= m) return true;
		
		count1 = count2 = 0;
		iz = z; ix = x;
		while (++iz < n && --ix >= 0 && board[ix][y][iz] == c) count1++;
		iz = z; ix = x;
		while (--iz >= 0 && ++ix < n && board[ix][y][iz] == c) count2++;
		if (count1+count2+1 >= m) return true;
		
		count1 = count2 = 0;
		ix = x; iy = y; iz = z;
		while (++ix < n && ++iy < n && ++iz < n && board[ix][iy][iz] == c) count1++;
		ix = x; iy = y;
		while (--ix >= 0 && --iy >= 0 && --iz >= 0 && board[ix][iy][iz] == c) count2++;
		if (count1+count2+1 >= m) return true;
		
		count1 = count2 = 0;
		ix = x; iy = y; iz = z;
		while (++ix < n && ++iy < n && --iz >= 0 && board[ix][iy][iz] == c) count1++;
		ix = x; iy = y;
		while (--ix >= 0 && --iy >= 0 && ++iz < n && board[ix][iy][iz] == c) count2++;
		if (count1+count2+1 >= m) return true;

		count1 = count2 = 0;
		ix = x; iy = y; iz = z;
		while (++ix < n && --iy >= 0 && ++iz < n && board[ix][iy][iz] == c) count1++;
		ix = x; iy = y;
		while (--ix >= 0 && ++iy < n && --iz >= 0 && board[ix][iy][iz] == c) count2++;
		if (count1+count2+1 >= m) return true;
		
		count1 = count2 = 0;
		ix = x; iy = y; iz = z;
		while (--ix >= 0 && ++iy < n && ++iz < n && board[ix][iy][iz] == c) count1++;
		ix = x; iy = y;
		while (++ix < n && --iy >= 0 && --iz >= 0 && board[ix][iy][iz] == c) count2++;
		if (count1+count2+1 >= m) return true;
		
		return false;
	}
	
	void run() {
		int p;
		W:while (true) {
			n = sc.nextInt(); m = sc.nextInt(); p = sc.nextInt();
			if (n == 0 && m == 0 && p == 0) break;
			int[] x = new int[p];
			int[] y = new int[p];
			for (int i = 0; i < p; i++) {
				x[i] = sc.nextInt()-1;
				y[i] = sc.nextInt()-1;
			}
			
			board = new int[n][n][n];
			int[][] num = new int[n][n];
			for (int i = 0; i < p; i++) {
				if (i % 2 == 0) {
					board[x[i]][y[i]][num[x[i]][y[i]]] = 1;
					if (isEnd(x[i],y[i],num[x[i]][y[i]],1)) {
						out.printf("Black %d\n", i+1);
						continue W;
					}
					num[x[i]][y[i]]++;
				} else {
					board[x[i]][y[i]][num[x[i]][y[i]]] = -1;
					if (isEnd(x[i],y[i],num[x[i]][y[i]],-1)) {
						out.printf("White %d\n", i+1);
						continue W;
					}
					num[x[i]][y[i]]++;
				}
			}
			out.println("Draw");
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}