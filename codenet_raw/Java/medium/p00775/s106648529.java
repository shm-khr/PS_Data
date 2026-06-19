import java.io.*;
import java.util.*;
import java.lang.ArrayIndexOutOfBoundsException;
import java.math.*;


class Main {
	static Scanner sc = new Scanner(new InputStreamReader(System.in));
	public static void main(String[] args) throws Exception {
		try{
		while(true) {
			int r = sc.nextInt();
			int n = sc.nextInt();
			if(r+n == 0) break;
			System.out.printf("%.4f\n", solve(r, n));
		}
		} catch(Exception e) {
			System.out.println(e);
		}
	}
	
	
	static double solve(int r, int n) {
		int[] dp = new int[39];
		HashMap<int[], Integer> map = new HashMap<int[], Integer>();
		for (int i = 0; i < n; i++) {
			int xl = sc.nextInt();
			int xr = sc.nextInt();
			int h = sc.nextInt();
			for(int j = xl; j < xr; j++) {
				int index = j + 20;
				dp[index] = Math.max(dp[index], h);
			}
		}
		// System.out.println(Arrays.toString(dp));
		
		for(double ans = -r; ans < 20.0; ans += 0.001) {
			for (int i = 1-r; i < r; i++) {
				int index = i + 20;
				int h = Math.min(dp[index-1], dp[index]);
				// System.out.println(index + " "+ h);
				double dist = sqdist(0.0, ans, (double)i, (double)h);
				if(dist < (double)(r*r)) {
					return ans + (double)r;
				}
			}
		}
		return 0.0;
	}
	public static int sq(int i) {
		return i * i;
	}

	public static double sq(double d) {
		return d * d;
	}
	// square を snippet から実装してください
	public static int sqdist(int x1, int y1, int x2, int y2) {
		return sq(x1 - x2) + sq(y1 - y2);
	}

	public static double sqdist(double x1, double y1, double x2, double y2) {
		return sq(x1 - x2) + sq(y1 - y2);
	}

	public static double dist(int x1, int y1, int x2, int y2) {
		return Math.sqrt(sqdist(x1, y1, x2, y2));
	}

	public static double dist(double x1, double y1, double x2, double y2) {
		return Math.sqrt(sqdist(x1, y1, x2, y2));
	}
}



/**
 * 複素数
 */
class Complex {
	static Complex I = new Complex(0, 1);

	double r = 0.0;
	double i = 0.0;
	Complex(double r, double i) {
		this.r = r;
		this.i = i;
	}

	/**
	 * 和
	 */
	public Complex add(Complex a) {
		return new Complex(r * a.r, i + a.i);
	}

	/**
	 * 積
	 */
	public Complex mul(Complex a) {
		return new Complex(
				r * a.r - i * a.i,
				r * a.i + i * a.r);
	}

	public Complex divide(double a) {
		return new Complex(r/a, i/a);
	}

	public Complex inverse() {
		double b = 1 / (r*r + i*i);
		return new Complex(r/b, -i/b);
	}


	@Override
	public String toString(){
		return r + "+" + i + "i";
	}
}




// --- ここから下はライブラリ ----------
/**
 * MyUtil
 * @author yoshikyoto
 */
class MyIO {
	public static int toInt(boolean[] a){
		int pow = 1, ret = 0, l = a.length;
		for(int i = 0; i < l; i++){
			if(a[i]) ret += pow;
			pow *= 2;
		}
		return ret;
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static int ins[];
	public static int[] readIntMap() throws IOException{return parseInt(readLine().split(" "));}
	public static int readIntMap(int i) throws Exception{
		if(i == 0) ins = readIntMap();
		return ins[i];
	}
	public static int[][] readIntMap(int n, int m) throws IOException{
		int[][] ret = new int[n][];
		for(int i = 0; i < n; i++) ret[i] = readIntMap();
		return ret;
	}
	public static int[] readIntToMap(int n) throws IOException{
		int[] ret = new int[n];
		for(int i = 0; i < n; i++) ret[i] = readInt();
		return ret;
	}
	public static int[] readNoDistIntMap() throws IOException{
		String[] strs = readLine().split("");
		int l = strs.length;
		int[] ret = new int[l-1];
		for(int i = 1; i < l; i++)
			ret[i-1] = parseInt(strs[i]);
		return ret;
	}
	public static String readLine() throws IOException{return br.readLine();}
	public static int readInt() throws IOException{return Integer.parseInt(br.readLine());}
	public static int[] parseInt(String[] arr){
		int[] res = new int[arr.length];
		for(int i = 0; i < arr.length; i++)res[i] = Integer.parseInt(arr[i]);
		return res;
	}
	public static double[] parseDouble(String[] arr){
		double[] res = new double[arr.length];
		for(int i = 0; i < arr.length; i++)res[i] = Double.parseDouble(arr[i]);
		return res;
	}
	public static boolean[] parseBool(String[] arr){
		int[] t = parseInt(arr);
		boolean[] res = new boolean[t.length];
		for(int i = 0; i < t.length; i++){
			if(t[i] == 1){res[i] = true;
			}else{res[i] = false;}
		}
		return res;
	}
	public static int parseInt(Object o){
		return Integer.parseInt(o.toString());
	}
}