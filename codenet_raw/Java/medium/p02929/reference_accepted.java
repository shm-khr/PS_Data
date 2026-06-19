//atcoder library for java 感謝します。
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

 
public class Main {
	static final long MOD=1000000007;//998244353;
	public static void main(String[] args) {
		PrintWriter out = new PrintWriter(System.out);
		InputReader sc=new InputReader(System.in);
		int N=sc.nextInt()*2;
		char[] cs=sc.next().toCharArray();
		int flag=0;//0ならB
		if (cs[0]=='W') {
			System.out.println(0);
			return;
		}
		int count=1;
		int[] c=new int[N];//0なら始点
		for (int i = 1; i < c.length; i++){
			if (count==0){
				if (flag==0&&cs[i]=='B') {
					System.out.println(0);
					return;
				}
				if (flag==1&&cs[i]=='W') {
					System.out.println(0);
					return;
				}
				count++;
			}else {
				if ((flag==0&&cs[i]=='W')||(flag==1&&cs[i]=='B')) {
					count++;
				}else {
					c[i]=1;
					count--;
				}
			}
			flag=(flag+1)%2;
		}
		if (count!=0) {
			System.out.println(0);
			return;
		}
		long ans=1;
		long cc=0;
		long dd=0;
		for (int i = 0; i < c.length; i++) {
			if (c[i]==0) {
				cc++;
			}else {
				ans*=(cc-dd);
				ans%=MOD;
				dd++;
			}
		}
		for (long i = 1; i <= N/2; i++) {
			ans=(ans*i)%MOD;
		}
		System.out.println(ans);
	}
		static class InputReader { 
		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;
		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}
 
		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}
 
		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}
 
		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}
 
		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}
 
		public boolean hasNext() {
			skip();
			return hasNextByte();
		}
 
		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
 
		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public double nextDouble() {
			return Double.parseDouble(next());
		}
 
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
 
		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
}
