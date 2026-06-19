
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main p = new Main();
	}

	public Main() {
		Scanner sc = new Scanner(System.in);
		while(true){
			int r = sc.nextInt();
			int n = sc.nextInt();
			if(r==0 && n==0)
				break;
			
			int[] xl = new int[n];
			int[] xr = new int[n];
			int[] h = new int[n];
			for(int i=0;i<n;i++){
				xl[i] = sc.nextInt();
				xr[i] = sc.nextInt();
				h[i] = sc.nextInt();
			}
			
			solve(r, n, xl, xr, h);
		}
	}

	public void solve(int r, int n, int[] xl, int[] xr, int[] h) {
		
		
		int[] cover = new int[2*r];
		for(int i=0;i<xl.length;i++){
			xl[i]+=r;
			xr[i]+=r;
			xl[i] = xl[i]<0 ? 0 : xl[i];
			xr[i] = xr[i]<0 ? 0 : xr[i];
			
			int ll = Math.min(xl[i], xr[i]);
			int rr = Math.min(r*2, Math.max(xl[i], xr[i]));
			
			int c = h[i];
			for(int j=ll;j<rr;j++){
				cover[j] = Math.max(cover[j], c);
			}
		}
		
//		System.out.println(Arrays.toString(cover));
		double res = 100000.0;
		for(int i=0;i<cover.length;i++){
			int xx = i-r>0 ? i-r+1 : r-i-1;
			double t1 = cover[i] + r*(1-Math.sin(Math.acos((double)Math.abs(r-i)/r)));
			double t2 = cover[i] + r*(1-Math.sin(Math.acos((double)xx/r)));
			res = Math.min(res, Math.min(t1,t2));
		}
		
		System.out.println(String.format("%.4f",res));
	}

}