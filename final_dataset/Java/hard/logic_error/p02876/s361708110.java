import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni();
		int[][] ab = new int[n][];
		for(int i = 0;i < n;i++){
			ab[i] = new int[]{ni(), ni(), -1};
		}
		long x = 0, y = 0;
		int[] bs = new int[n];
		int p = 0;
		int q = 0;
		for(int i = 0;i < n;i++){
			if(ab[i][1] - ab[i][0] > 0){
				x++;
				y += ab[i][0];
				bs[p++] = ab[i][1];
			}else{
				ab[q++] = ab[i];
			}
		}
		ab = Arrays.copyOf(ab, q);
		bs = Arrays.copyOf(bs, p);
//		if(p == 0){
//			out.println(0);
//			return;
//		}
		
		Arrays.sort(bs);
		
		Arrays.sort(ab, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		for(int i = 0;i < q;i++){
			ab[i][2] = i;
		}
		Arrays.sort(ab, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[1] - b[1]);
			}
		});
		int[] iord = new int[q];
		for(int i = 0;i < q;i++)iord[i] = ab[i][2];
		Arrays.sort(ab, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		
		int[] as = new int[q];
		for(int i = 0;i < q;i++)as[i] = ab[i][0];
		long[] ft = new long[q+5];
		long[] nums = new long[q+5];
		for(int i = 0;i < q;i++){
			addFenwick(ft, i, ab[i][0]);
			addFenwick(nums, i, 1);
		}
		
		long[] ans = {0L, 1L};
		int r = 0;
		for(int i = p-1;i >= 0;i--){
			long ny = y - bs[i];
			while(r < q && ab[iord[r]][1] >= bs[i]){
				addFenwick(ft, iord[r], -ab[iord[r]][0]);
				addFenwick(nums, iord[r], -1);
				r++;
			}
			
			if(ny <= 0){
				long rem = -ny;
				int ind = firstGEFenwick(ft, rem+1);
				ind--;
				int sup = lowerBound(as, (int)bs[i]);
				sup--;
				ind = Math.min(ind, sup);
				
				long vx = x + sumFenwick(nums, ind);
				long vy = y + sumFenwick(ft, ind);
				long[] o = reduce(new long[]{vx*bs[i]-vy, bs[i]});
				ans = max(ans, o);
				// vx - vy/bs[i]
			}
			x--;
			y = ny;
		}
		ans = div(ans, new long[]{n, 1});
		out.println(ans[0] + " " + ans[1]);
	}
	
	
	
	public static int lowerBound(int[] a, int v){ return lowerBound(a, 0, a.length, v); }
	public static int lowerBound(int[] a, int l, int r, int v)
	{
		if(l > r || l < 0 || r > a.length)throw new IllegalArgumentException();
		int low = l-1, high = r;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] >= v){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
	}

	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}

	public static int firstGEFenwick(long[] ft, long v)
	{
		int i = 0, n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0;b >>= 1){
			if((i|b) < n && ft[i|b] < v){
				i |= b;
				v -= ft[i];
			}
		}
		return i;
	}

	
	public static long[] reduce(long[] f)
	{
		if(f[1] == 0) { // n/0
			f[0] = 1;
		}else if(f[0] == 0) { // 0/n
			f[1] = 1;
		}else {
			if(f[1] < 0) { // -a/-b ->a/b
				f[0] = -f[0];
				f[1] = -f[1];
			}
			long a = Math.abs(f[0]), b = f[1];
			while (b > 0) {
				long c = a;
				a = b;
				b = c % b;
			}
			f[0] /= a;
			f[1] /= a;
		}
		return f;
	}
	
	public static long[] add(long[] a, long[] b){ return reduce(new long[]{a[0]*b[1]+a[1]*b[0], a[1]*b[1]}); }
	public static long[] sub(long[] a, long[] b){ return reduce(new long[]{a[0]*b[1]-a[1]*b[0], a[1]*b[1]}); }
	public static long[] mul(long[] a, long[] b){ return reduce(new long[]{a[0]*b[0], a[1]*b[1]}); }
	public static long[] div(long[] a, long[] b){ return reduce(new long[]{a[0]*b[1], a[1]*b[0]}); }
		
	public static int compare(long[] a, long[] b){return Long.signum(a[0] * b[1] - a[1] * b[0]);}
	
	public static long[] min(long[] a, long[] b){ return compare(a, b) <= 0 ? a : b; }
	public static long[] max(long[] a, long[] b){ return compare(a, b) >= 0 ? a : b; }
	
	public static int lowerBound(long[][] es, int p, long[] r)
	{
		int low = -1, high = p;
		while(high-low > 1){
			int h = high+low>>>1;
			if(Long.compare(r[0]*es[h][1], r[1]*es[h][0]) <= 0){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
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
