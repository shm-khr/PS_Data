/*
* @Author Silviase(@silviasetitech)
* For ProCon
*/

import java.util.*;
import java.lang.*;
import java.math.*;

public class Main{    
    static int[] parent;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[][] num = new int[n+1][n+1];
        if (n % 2 == 0) {
            if (n  == 2) {
                System.out.println(-1);
                return;
            }else{
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (i > (n/2)) {   // shita
                            if (j <= (n/2)) { // hidari
                                num[i][j] = j;
                            }else{ // migisita
                                num[i][j] = (j+1+(i-(n/2)-1)) % n;
                                if (num[i][j] <= n/2) {
                                    if (num[i][j] == 0) {
                                        num[i][j] = n;
                                    }else{
                                        num[i][j] += n/2;
                                    }
                                }
                            }
                        }else{
                            // migiue
                            if (j > n/2) {
                                num[i][j] = j;
                            }else{
                            //hidariue
                                if (i == n/2 && j == 1) {
                                    num[i][j] = n;
                                }else{
                                    if (j - i ==1) {
                                        num[i][j] = n;
                                    }else{
                                        if (j == 1) {
                                            num[i][j] = i+1;
                                        }else{
                                            num[i][j] = num[i][j-1] + 1;
                                            if (num[i][j-1] == n) {
                                                num[i][j] = num[i][j-2] + 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }else{
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    num[i][j] = (i+j+2) % n;
                    if (num[i][j] == 0) {
                        num[i][j] += n;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n-1; j++) {
                System.out.print(num[i][j] + " ");        
            }
            System.out.println("");
        }

        sc.close();
    }


    /**
     * UnionFind
     */
    public static class UnionFind {
        

        public static void UFTreeInit(int size) {
            parent = new int[size];
            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }

        public static int Find(int x) {
            if (parent[x] == x) {  // findParent[x]
                return x;
            } else {
                return parent[x] = Find(parent[x]);
            }
        }

        public static boolean isSameRoot(int x, int y) {
            return (Find(x) == Find(y));
        }

        public static void Union(int x, int y) {
            x = Find(x);
            y = Find(y);
            if (x == y) {
                return;
            } else {
                parent[y] = x;
            }
        }
    }
    

}

class Algorithm{

    static long MOD = 1000000007;
    static int MAX = 510000;
    static long[] finv = new long[MAX];
    static long[] inv = new long[MAX];
    static long[] fac = new long[MAX];

    

    public static int ManhattanDist(int x, int y, int xx, int yy) {
        return(Math.abs(xx-x) + Math.abs(yy-y));
    }

    static long modpow(long a, long n, long mod) {
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1) res = res * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    }
    
    
    static long modinv(long a, long mod) {
        return modpow(a, mod - 2, mod);
    }

    static void nCkmake() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[(int)MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    
    static long nCk(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }

    public static long gcd_long(long a, long b) {
        if (a < b) {
            long x = a;
            a = b;
            b = x;
        }
        if (b == 0) {
            return a;
        }else{
            return gcd_long(b, a%b);
        }
    }

    public static long lcm_long(long a, long b) {
        long gcd = gcd_long(a,b);
        return a/gcd*b;
    }

    public static long GyakuGenMOD(long a) {
        return RepSquareMethod(a, MOD-2);
    }
    
    public static long factmod(int a) {
        long[] fact = new long[a+1];
        fact[0] = fact[1] = 1;
        for (int i = 2; i <= a; i++) {
            fact[i] = (fact[i-1]*i)%MOD;
        }
        return fact[a];
    }

    public static long RepSquareMethod(long a, long n) { // a^n
        long ans = 1;
        while (n > 0) {
            if ( n % 2 == 1) {
                ans = (ans * a) % MOD;
            }
            a = (a*a)%MOD;
            n/=2;
        }
        return ans;
    }
}

