import java.util.*;

import javax.xml.crypto.Data;

import java.math.*;
import java.awt.geom.*;
import java.io.*;
     
     
public class Main {
	static int W;
	static int H;
	static int N;
	static boolean[][] fld;
	static int[] vx = new int[] {0,1,0,-1};
	static int[] vy = new int[] {1,0,-1,0};
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int r = sc.nextInt();
			int n = sc.nextInt();
			if(r == 0 && n == 0) break;
			int[] max = new int[50];
			int[] cc  = new int[50];
			boolean[] xx = new boolean[50];
			for(int i = 0; i < n; i++) {
				int xa = sc.nextInt();
				int xb = sc.nextInt();
				int h = sc.nextInt();
				if(xx[xa + 20]) {
					max[xa + 20] = Math.max(Math.min(h, cc[xa + 20]),max[xa + 20]);
				}
				else {
					xx[xa + 20] = true;
					cc[xa + 20] = h;
				}
				if(xx[xb + 20]) {
					max[xb + 20] = Math.max(Math.min(h, cc[xb + 20]),max[xb + 20]);
				}
				else {
					xx[xb + 20] = true;
					cc[xb + 20] = h;
				}
				
				
				
				
				for(int j = xa + 21; j < xb + 20; j++) {
					max[j] = Math.max(max[j], h);
				}
			}
			double t = Integer.MAX_VALUE;
			
			for(int i = 0; i < 50; i++) {
				int x = i-20;
				int y = max[i];
				int D = 4 * (r + y)*(r + y) - 4 * (x * x + y * y + 2 * r * y);
				if(D <= 0) continue; 
				double tt = (2 * (r + y) - Math.sqrt(4 * (r + y)*(r + y) - 4 * (x * x + y * y + 2 * r * y))) / 2 + 0.0000000000000001;
				t = Math.min(tt, t);
			}
			System.out.printf("%.20f\n",t);
			
			
			
			
		}
	}
}