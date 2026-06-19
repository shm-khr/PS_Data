import java.util.HashMap;
import java.util.Scanner;

public class Main{
	//	public static HashMap<Integer, Integer> hei = new HashMap<Integer, Integer>();
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		while(true){
			int r = in.nextInt();
			int n = in.nextInt();
			if(r == 0) break;
			int[] h = new int[41];
			for(int i=0; i<n; i++){
				int xl = in.nextInt();
				int xr = in.nextInt();
				int hei = in.nextInt();
				for(int j=xl+20; j<xr+20; j++){
					h[j] = Math.max(h[j], hei);
				}
			}
			int[] p = new int[r*2-1];
			for(int i=-r+1; i<r; i++){
				p[i+r-1] = Math.min(h[20+i], h[20+i-1]);
			}
			double[] circle = new double[r*2-1];
			for(int i=-r+1; i<r; i++){
				circle[i+r-1] = Math.sqrt(r*r-i*i)-r;
			}
			double res = 0;
			out: for(double t=0.00001; t<=20.00000; t+=0.00001){
				for(int i=0; i<r*2-1; i++){
					if(circle[i]+t > p[i]){
						res = t-0.00001;
						break out;
					}
				}
			}
			System.out.println(res);
		}
	}

	//	public static void setMap(int x, int y){
	//		if(hei.containsKey(x)){
	//			int by = hei.get(x);
	//			
	//		}else{
	//			hei.put(x, y);
	//		}
	//	}
}