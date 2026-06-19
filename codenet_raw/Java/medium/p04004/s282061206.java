import java.awt.geom.Point2D;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.*;

 
 
 
public class Main {
	public static long C(int n, int r)
	{
		if(n < 0 || r < 0 || r > n)return 0;
		if(r > n / 2)r = n - r;
		return FACT[n]*IFACT[n-r]%mod*IFACT[r]%mod;
	}
	 
	static long[] FACT, IFACT;

	 
		
	static int MOD = 1000000007;
	static int mod = MOD;
	public static void main(String[] args) {
		int n = 900000;
		FACT = new long[n+1];
		IFACT = new long[n+1];
		FACT[0] = 1;
		IFACT[0] = 1;
		BigInteger MODBI = new BigInteger(String.valueOf(mod));
		for(int i = 1;i <= n;i++){
			FACT[i] = FACT[i-1] * i % mod;
			IFACT[i] = new BigInteger(String.valueOf(FACT[i])).modInverse(MODBI).longValue();
		}
		Scanner sc = new Scanner(System.in);
		PrintStream out = new PrintStream(System.out);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int K = sc.nextInt();
		long ans = 0;
		
		for(int i = N; i <= N + M + K; i++) {
			int retA = modPow(3,N + M + K - i);
			
			int retB = (int)C(i-1,N-1);
			int kMax = Math.max(0, i - N-K);
			int kMin = Math.min(i - N, M);
			long sum = 0;
			for(int k = kMax; k <= kMin; k++) {
				sum += (int)C(i - N, k) % MOD;
				sum %= MOD;
			}
			long ansA = ((long)(retA) * (long)(retB)) % MOD;
			ansA *= sum % MOD;
			ansA %= MOD;
			ans += ansA;
			ans %= MOD;
		}
		System.out.println(ans);
	}
	public static int modPow(int a, int b) {
		if(b == 0) return 1 % MOD;
		if(b == 1) return a % MOD;
		
		if(b % 2 == 0) {
			long ret = modPow(a % MOD,b / 2) % MOD;
			return (int)((ret * ret) % MOD);
		}
		else {
			long ret = (a * (long)modPow(a % MOD,b-1)) % MOD;
			return (int)(ret % MOD);
		}
	}
	public static int comb(int n, int k) {
		if(k == 0) return 1;
		long AA = 1;
		for(int i = 0; i < k; i++) {
			AA *= (long)n - i;
			AA %= MOD;
		}
		for(int i = 1; i <= k; i++) {
			AA *= new BigInteger(String.valueOf(i)).modInverse(new BigInteger(String.valueOf(MOD))).longValue();
			AA %= MOD;
		}
		return (int)(AA % MOD);
	}


}