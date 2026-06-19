import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
	    FastScanner sc = new FastScanner(System.in);
	    PrintWriter pw = new PrintWriter(System.out);
	    long mod = (long)1e9 + 7;
		char[] s = sc.next().toCharArray();
		int n = s.length;
		long[][] dp = new long[n + 1][4];
		dp[0][3] = 1;
		for(int i = n; i >= 0; --i){
            for(int j = 3; j >= 0; --j){
                if(i == n){
                    dp[i][j] = (j == 3 ? 1 : 0);
                }else{
                    dp[i][j] = dp[i+1][j] * (s[i] == '?' ? 3L : 1L);
                    if(j < 3 && (s[i] == '?' || s[i] == "ABC".charAt(j))){
                        dp[i][j] += dp[i+1][j+1];
                    }
                    dp[i][j] %= mod;
                }
            }
        }
        pw.println(dp[0][0]);
        pw.flush();
	}
}


class FastScanner {
    private BufferedReader reader = null;
    private StringTokenizer tokenizer = null;
    public FastScanner(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }

    public String next() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken("\n");
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
         return Double.parseDouble(next());
    }
    
    public String[] nextArray(int n) {
        String[] a = new String[n];
        for (int i = 0; i < n; i++)
            a[i] = next();
        return a;
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
}
