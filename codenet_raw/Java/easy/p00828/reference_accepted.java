import java.util.*;
public class Main { 
	static int n;
	static int m;
	static int p;
	static int[][][] map;
	static int[][] list;
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		while(true) {
			n = stdIn.nextInt();
			m = stdIn.nextInt();
			p = stdIn.nextInt();
			if(n == 0 && m == 0 && p == 0) break;
			map = new int[n][n][n];
			list = new int[n][n];
			//-1 blank 0 black 1 white
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					list[i][j] = 0;
					for(int k = 0; k < n; k++) {
						map[i][j][k] = -1;
					}
				}
			}
			boolean isEnd = false;
			boolean isBlack = true;
			boolean blackWin = false;
			int when = 0;
			for(int i = 0; i < p; i++) {
				int x = stdIn.nextInt();
				int y = stdIn.nextInt();
				x -=1;
				y -=1;
				
				if(isEnd) continue;
				
				map[x][y][list[x][y]++] = (isBlack)?0:1;
				int ans = check();
				if(ans == 0) {
					blackWin = true;
					isEnd = true;
					when = i+1;
				}
				else if(ans == 1){
					blackWin = false;
					isEnd = true;
					when = i+1;
				}
				
				if(isBlack) {
					isBlack = false;
				}
				else {
					isBlack = true;
				}
				
			}
			if(!isEnd) {
				System.out.println("Draw");
			}
			else if(blackWin) {
				System.out.println("Black " + when);
			}
			else {
				System.out.println("White " + when);
			}
			
			
		}
	}
	
	public static int check() {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					for(int dx = -1; dx <= 1; dx++) {
						for(int dy = -1; dy <= 1; dy++) {
							for(int dz = -1; dz <= 1; dz++) {
								if(dx == 0 && dy == 0 && dz == 0) continue;
								int a = i;
								int b = j;
								int c = k;
								int whitecount = 0;
								int blackcount = 0;
								while(true) {
									if(!isOK(a,b,c)) break;
									if(map[a][b][c] == 0) {
										blackcount++;
										whitecount = 0;
									}
									else if(map[a][b][c] == 1) {
										whitecount++;
										blackcount = 0;
									}
									else if(map[a][b][c] == -1) {
										whitecount = 0;
										blackcount = 0;
									}
									
									
									if(blackcount >= m) {
										return 0;
									}
									if(whitecount >= m) {
										return 1;
									}
									
									a += dx;
									b += dy;
									c += dz;
								}
							}
						}
					}
				}
			}
		}
		return -1;
		
	}
	
	public static boolean isOK(int a, int b, int c) {
		if(a == -1 || b == -1 || c == -1 || a >= n || b >= n || c >= n) return false;
		return true;
	}
}

	