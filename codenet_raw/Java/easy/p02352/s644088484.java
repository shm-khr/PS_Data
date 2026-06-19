import java.io.*;
import java.util.*;
import java.util.Map.Entry;
import java.util.stream.Collectors;

@SuppressWarnings("unused")
public class Main {
	
	//final boolean isDebug = true;
	final boolean isDebug = false;
	String fileName = "input.txt";
	FastScanner sc;
	PrintWriter out;
	final int MOD = (int)1e9+7;
	//final int INF = Integer.MAX_VALUE / 2;
	final long INF = Long.MAX_VALUE / 2;
	
	void solve() throws Exception{
		int n = sc.nextInt();
		LazySegmentTree seg = new LazySegmentTree(new long[n]);
		int q = sc.nextInt();
		for(int i = 0; i < q; i++){
			if(sc.next().equals("0")){
				int s = sc.nextInt(), t = sc.nextInt(), x = sc.nextInt();
				seg.add(s, t+1, x);
			}else{
				int s = sc.nextInt(), t = sc.nextInt();
				System.out.println(seg.getMin(s, t+1));
			}
		}
	}
	
	/* end solve */
	
	/* main */
	public static void main(String[] args) throws Exception {
		new Main().m();
	}
	
	void m() throws Exception {
		long S = System.currentTimeMillis();
		sc = (isDebug) ? new FastScanner(new FileInputStream(fileName)) : new FastScanner(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		if(isDebug){
			System.out.println("---Debug---");
			System.out.printf("%8d ms\n", (G-S));
		}
	}
	/* end main */
}
/* end Main */

class LazySegmentTree{
	int n;
	long[] node, lazy;
	
	//元配列vをセグメント木で表現する
	public LazySegmentTree(long[] v){
		int sz = v.length;
		n = 1;
		while(n < sz) n *= 2;
		node = new long[2*n-1];
		lazy = new long[2*n-1];
		
		for(int i = 0; i < sz; i++)
			node[i+n-1] = v[i];
		
		for(int i = n-2; i >= 0; i--)
			node[i] = Math.min(node[i*2+1], node[i*2+2]);
	}
	
	//k番目のノードについて遅延評価を行う
	public void eval(int k, int l, int r){

	    /*
	     * 遅延配列が空でない場合、
	     * 自ノード及び子ノードへの値の伝播が起こる
	     */
		if(lazy[k] != 0){
			//区間加算
			node[k] += lazy[k];
			
			/*
			 * 最下段かどうかのチェックをしよう
			 * 子ノードは親ノードの 1/2 の範囲であるため、
			 * 伝播させるときは半分にする
			 */
			if(r - l > 1){
				//区間加算
				lazy[2*k+1] += lazy[k] / 2;
				lazy[2*k+2] += lazy[k] / 2;
			}
			
			/*伝播が終わったので、自ノードの遅延配列を空にする*/
			lazy[k] = 0;
		}
	}
	
	/*
	 * 指定した区間[a,b)全体にxを加算する
	 */
	public void add(int a, int b, long x){
		add(a, b, x, 0, 0, -1);
	}
	
	public void add(int a, int b, long x, int k, int l, int r){
		if(r < 0) r = n;
		
		//k番目のノードに対して遅延評価を行う
		eval(k, l, r);
		
		//範囲外なら何もしない
		if(b <= l || r <= a) return;
		
		if(a <= l && r <= b) {
			//完全に被覆しているならば、遅延配列に値を入れた後に評価
			lazy[k] += (r - l) * x;
			eval(k, l, r);
		}else{
			//そうでないならば、子ノードの値を再帰的に計算して、
			//計算済みの値をもらってくる
			add(a, b, x, 2*k+1, l, (l+r)/2);
			add(a, b, x, 2*k+2, (l+r)/2, r);
			node[k] = Math.min(node[2*k+1], node[2*k+2]);
		}
	}
	
	/*
	 * 指定した区間[a,b)の和を取得する
	 */
	long getMin(int a, int b){
		return getMin(a, b, 0, 0, -1);
	}
	
	long getMin(int a, int b, int k, int l, int r) {
		if(r < 0) r = n;
		//関数が呼び出されたら評価！
		eval(k, l, r);
		
		if(b <= l || r <= a) return Long.MAX_VALUE;
		if(a <= l && r <= b) return node[k];
		long vl = getMin(a, b, 2*k+1, l, (l+r)/2);
		long vr = getMin(a, b, 2*k+2, (l+r)/2, r);
		return Math.min(vl, vr);
	}
}

class FastScanner {
    private InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    public FastScanner(InputStream in) {
		this.in = in;
	}
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() {
    	if (hasNextByte()) return buffer[ptr++];
    	else return -1;
    }
    private static boolean isPrintableChar(int c){
    	return 33 <= c && c <= 126;
    }
    public boolean hasNext() {
    	while(hasNextByte() && !isPrintableChar(buffer[ptr]))
    		ptr++; return hasNextByte();
    }
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public String nextLine() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(b != 10) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() {
    	return Double.parseDouble(next());
    }
}

