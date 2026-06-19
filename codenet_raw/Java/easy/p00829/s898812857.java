import java.io.*;
import java.util.*;
import java.lang.ArrayIndexOutOfBoundsException;
import java.math.BigInteger;

/**
 * @author yoshikyoto
 */
class Main extends MyUtil{
	static int n;
	static long mod = 1L << 32;
	
	public static void main(String[] args) throws Exception{
		System.out.println(mod);
		System.out.println(mod ^ 1L);
		Scanner sc = new Scanner(new InputStreamReader(System.in));
		int n = sc.nextInt();
		for(int i = 0; i < n; i++){
			long[] c = new long[9];
			for(int j = 0; j < 9; j++){
				c[j] = Long.parseLong(sc.next(), 16);
			}
			// System.out.println(Arrays.toString(c));
			
			long d = 1;
			long k = 0;
			for(int j = 0; j < 32; j++){
				long a = (sum(c) / d) % 2;
				long b = (c[8] / d) % 2;
				// System.out.println(a + " " + b);
				
				if(a != b){
					// System.out.println(Long.toBinaryString(d));
					k += d; 
					xor(c, d);
				}
				// System.out.println(Arrays.toString(c));
				d *= 2;
			}
			System.out.println(Long.toHexString(k));
		}
	}
	
	static void xor(long[] arr, long k){
		for(int i = 0; i < 8; i++){
			arr[i] = arr[i] ^ k;
		}
	}
	
	static long sum(long[] arr){
		long sum = 0;
		for(int i = 0; i < 8; i++){
			sum += arr[i];
			sum %= mod;
		}
		return sum;
	}
}


class Node{
	static Node prev;
	// nextは兄弟ノード
	Node parent, child, next;
	int depth = 0;
	String name;
	
	public Node(String str){
		int i = 0;
		while(str.charAt(i) =='.')
			i++;
		depth = i;
		name = str.substring(i);
		
		while(prev != null){
			if(prev.depth == depth - 1)
				parent = prev;
			
			if(prev.depth == depth){
				prev.next = this;
				parent = prev.parent;
				break;
			}
			prev = prev.parent;
		}
		prev = this;
	}
	
	@Override
	public String toString(){
		StringBuffer buf = new StringBuffer(name);
		if(depth != 0){
			buf.insert(0, '+');
			if(parent.parent != null){
				parent.appendString(buf);
			}
		}
		return buf.toString();
	}
	
	public void appendString(StringBuffer buf){
		if(parent == null) return;

		if(next != null){
			buf.insert(0, '|');
		}else{
			buf.insert(0, ' ');
		}
		if(parent != null){
			parent.appendString(buf);
		}
	}
}

// --- ここから下はライブラリ ----------
/**
 * MyUtil
 * @author yoshikyoto
 */
class MyUtil {
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