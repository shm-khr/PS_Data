import java.io.*;
import java.util.*;

public class Main{
	static long mod;
	static long[][]memo;
	static long comb[][];
	static void preProcessNCR2(int maxN)		// O(N * N)
	{
		comb = new long[maxN][maxN];
		comb[0][0] = 1;
		for (int i = 1; i < maxN; i++)
		{
			comb[i][0] = 1;
			for (int j = 1; j <= i; j++)
				comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%mod;
		}
	}
	public static long ncr2(int n,int r) {
		return comb[n][r];
	}
	static long dp(int goodBits,int cntMasks) {
		if(cntMasks>goodBits || goodBits<0 || cntMasks<0)return 0l;
		if(memo[goodBits][cntMasks]!=-1)return memo[goodBits][cntMasks];
		if(goodBits==cntMasks) {
			return memo[goodBits][cntMasks]=1l;
		}
		//cur bit makes a new mask
		long newMask=dp(goodBits-1, cntMasks-1);
		//cur bit doesn't join any mask
		long noJoin=dp(goodBits-1, cntMasks);
		//cur bit joins one of the existed masks
		long join=(dp(goodBits-1, cntMasks)*1l*cntMasks)%mod;
		
		return memo[goodBits][cntMasks]=(newMask+noJoin+join)%mod;
	}
	static void main() throws Exception{
		int n=sc.nextInt();
		mod=sc.nextInt();
		long[]twoPower=new long[(n+1)*(n+1)],twoPowerTwoPower=new long[(n+1)*(n+1)];
		twoPower[0]=1;
		twoPowerTwoPower[0]=2;
		for(int i=1;i<twoPower.length;i++) {
			twoPower[i]=(twoPower[i-1]*2)%mod;
			//2^(2^(x-1))*2^(2^(x-1))=2^(2^(x-1) + 2^(x-1))=2^(2^(x-1)*(1+1))=2^(2^(x))
			twoPowerTwoPower[i]=(twoPowerTwoPower[i-1]*twoPowerTwoPower[i-1])%mod;
		}
		
		preProcessNCR2(n+1);
		memo=new long[n+1][n+1];
		for(long[]i:memo)Arrays.fill(i, -1);
		long ans=0;
		//choosing bits so that the count of each bit from the chosen bits in all masks is at most 1
		for(int goodBits=0;goodBits<=n;goodBits++) {
			long cur=0;
			//cnt masks that has count at most 1 of each one of (goodBits) bits
			for(int cntMasks=0;cntMasks<=goodBits;cntMasks++) {
				//cnt is the number of subsets of size (cntMasks) where each good bit is used at most once
				long cnt=dp(goodBits, cntMasks);
				
				//fill the remaining bad bits in each mask with anything
				long fill=twoPower[cntMasks*(n-goodBits)];
				
				long inc=(fill*cnt)%mod;
				cur=(cur+inc)%mod;
			}
			//cur is the number of subsets of masks where (goodBits) have at most one bit
			//choose which bits from the n
			cur=(cur*ncr2(n, goodBits))%mod;
			
			//we can use any subset of masks which has zeros in the good bits and anything in the bad bits
			cur=(cur*twoPowerTwoPower[n-goodBits])%mod;
			if((goodBits&1)==0) {
				ans=(ans+cur)%mod;
			}
			else {
				ans=(ans-cur+mod)%mod;
			}
		}
		pw.println(ans);
	}
	public static void main(String[] args) throws Exception{
		sc=new MScanner(System.in);
		pw = new PrintWriter(System.out);
		int tc=1;
//		tc=sc.nextInt();
		while(tc-->0)
			main();
		pw.flush();
	}
	static PrintWriter pw;
	static MScanner  sc;
	static class MScanner {
		StringTokenizer st;
		BufferedReader br;
		public MScanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}
 
		public MScanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public int[] intArr(int n) throws IOException {
	        int[]inArr=new int[n];for(int i=0;i<n;i++)inArr[i]=nextInt();
	        return inArr;
		}
		public long[] longArr(int n) throws IOException {
	        long[]inArr=new long[n];for(int i=0;i<n;i++)inArr[i]=nextLong();
	        return inArr;
		}
		public int[] intSortedArr(int n) throws IOException {
	        int[]inArr=new int[n];for(int i=0;i<n;i++)inArr[i]=nextInt();
	        shuffle(inArr);
	        Arrays.sort(inArr);
	        return inArr;
		}
		public long[] longSortedArr(int n) throws IOException {
	        long[]inArr=new long[n];for(int i=0;i<n;i++)inArr[i]=nextLong();
	        shuffle(inArr);
	        Arrays.sort(inArr);
	        return inArr;
		}
		public Integer[] IntegerArr(int n) throws IOException {
	        Integer[]inArr=new Integer[n];for(int i=0;i<n;i++)inArr[i]=nextInt();
	        return inArr;
		}
		public Long[] LongArr(int n) throws IOException {
	        Long[]inArr=new Long[n];for(int i=0;i<n;i++)inArr[i]=nextLong();
	        return inArr;
		}
		public String nextLine() throws IOException {
			return br.readLine();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
 
		public char nextChar() throws IOException {
			return next().charAt(0);
		}
 
		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
	static void shuffle(int[]inArr) {
		for(int i=0;i<inArr.length;i++) {
			int idx=i+(int)(Math.random()*(inArr.length-i));
			int tmp=inArr[i];
			inArr[i]=inArr[idx];
			inArr[idx]=tmp;
		}
	}
	static void shuffle(long[]inArr) {
		for(int i=0;i<inArr.length;i++) {
			int idx=i+(int)(Math.random()*(inArr.length-i));
			long tmp=inArr[i];
			inArr[i]=inArr[idx];
			inArr[idx]=tmp;
		}
	}
	static void shuffle(String[]inArr) {
		for(int i=0;i<inArr.length;i++) {
			int idx=i+(int)(Math.random()*(inArr.length-i));
			String tmp=inArr[i];
			inArr[i]=inArr[idx];
			inArr[idx]=tmp;
		}
	}
}