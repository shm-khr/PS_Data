import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
//		for(int a = 1;a <= 1000;a++){
//			for(int b = 1;b <= 1000;b++){
//				tr(a, b);
//				String F = f(a, b);
//				String G = g(a, b);
//				if(!F.equals(G))tr(a, b, F, G, F.equals(G));
//			}
//		}
		for(int Q = ni();Q > 0;Q--){
			out.println(f(ni(), ni()).substring(ni()-1, ni()));
		}
	}
	
	static String g(int a, int b)
	{
		int h = (b+a)/(Math.min(a, b) + 1);
		// L R
		// 0 <= a - (Lh + R) <= h
		// 0 <= b - (L + Rh) <= h
		// R <= a-Lh
		// R >= a - (L+1)h
		// (b - L - h)/h <= R
		// R <= (b-L)/h
		// a = 10, b = 7, h = 2
		
		// R = 0
		int L = 0, R = 0;
		int ll = Math.min(a/h, b);
		if(0 < a-h*ll && a-h*ll <= h && b-ll <= h ||
				a-h*ll == 0 && b-ll <= h-1
				){
			L = ll;
			R = 0;
		}else{
			int low = 0, high = ll;
			while(high - low > 1){
				int mid = high+low>>1;
				int ra = a-mid*h, rb = b-mid;
				int rr = Math.min(rb/h, ra);
				ra -= rr; rb -= rr * h;
				if(ra >= h || ra <= h && rb <= h && 
						!(ra == h && rb == 0) &&
						!(ra == 0 && rb == h)){
					low = mid;
				}else{
					high = mid;
				}
			}
			if(low <= 0){
				L = 0;
				R = Math.min(b/h, a);
			}else{
				L = low;
				int ra = a-L*h, rb = b-L;
				R = Math.min(rb/h, ra);
			}
		}
		
		char[] ret = new char[a+b];
		int p = 0;
		for(int i = 0;i < L;i++){
			for(int j = 0;j < h;j++){
				ret[p++] = 'A'; a--;
			}
			ret[p++] = 'B'; b--;
		}
		int q = ret.length-1;
		for(int i = 0;i < R;i++){
			for(int j = 0;j < h;j++){
				ret[q--] = 'B'; b--;
			}
			ret[q--] = 'A'; a--;
		}
		while(a > 0){
			ret[p++] = 'A'; a--;
		}
		while(b > 0){
			ret[p++] = 'B'; b--;
		}
		return new String(ret);
	}
	
	// (b+a)/(min(a,b)+1)
	
	static String f(int a, int b)
	{
		int h = (b+a)/(Math.min(a, b) + 1);
		int n = a+b;
		String ans = "~";
		for(int L = Math.min(a/h, b);L >= 0;L--){
			outer:
			for(int R = Math.min(a-h*L, (b-L)/h);R >= 0;R--){
//			for(int R = 0;h*L+R <= a && L+R*h <= b;R++){
				
				int A = a, B = b;
				char[] ret = new char[A+B];
				int p = 0;
				for(int i = 0;i < L;i++){
					for(int j = 0;j < h;j++){
						ret[p++] = 'A'; A--;
					}
					ret[p++] = 'B'; B--;
				}
				int q = ret.length-1;
				for(int i = 0;i < R;i++){
					for(int j = 0;j < h;j++){
						ret[q--] = 'B'; B--;
					}
					ret[q--] = 'A'; A--;
				}
				while(A > 0){
					ret[p++] = 'A'; A--;
				}
				while(B > 0){
					ret[p++] = 'B'; B--;
				}
				int rep = 1;
				for(int i = 1;i < a+b;i++){
					if(ret[i] == ret[i-1]){
						rep++;
					}else{
						rep = 1;
					}
					if(rep > h)continue outer;
				}
				String r = new String(ret);
				return r;
//				if(r.compareTo(ans) < 0){
//					ans = r;
//				}
			}
		}
		return ans;
	}
	
	public static void main(String[] args) throws Exception
	{
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	private static boolean eof()
	{
		if(lenbuf == -1)return true;
		int lptr = ptrbuf;
		while(lptr < lenbuf)if(!isSpaceChar(inbuf[lptr++]))return false;
		
		try {
			is.mark(1000);
			while(true){
				int b = is.read();
				if(b == -1){
					is.reset();
					return true;
				}else if(!isSpaceChar(b)){
					is.reset();
					return false;
				}
			}
		} catch (IOException e) {
			return true;
		}
	}
	
	private static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;
	
	private static int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
//	private static boolean isSpaceChar(int c) { return !(c >= 32 && c <= 126); }
	private static int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private static double nd() { return Double.parseDouble(ns()); }
	private static char nc() { return (char)skip(); }
	
	private static String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private static char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private static char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private static int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private static int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}
