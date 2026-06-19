import java.util.*;

class Main {
    static final long MOD=1000000007;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n=scan.nextInt();
        int m=scan.nextInt();
        long[][][]dp=new long[m+1][n][n];
        dp[0][0][0]=1;
        for(int i=0;i<m;++i){
            int u=i%2;
            for(int j=0;j<n;++j)Arrays.fill(dp[1-u][j],0);
            for(int j=0;j<n;++j)
                for(int k=0;k<n;++k){
                    if(j<n-1){
                        dp[1-u][j+1][k]+=dp[u][j][k];
                        dp[1-u][j+1][k]%=MOD;
                    }
                    dp[1-u][j][j]+=(k+1)*dp[u][j][k];
                    dp[1-u][j][j]%=MOD;
                    dp[1-u][j][k]+=(j-k)*dp[u][j][k];
                    dp[1-u][j][k]%=MOD;
                }
        }
        long t=0;
        for(int i=0;i<n;++i)
            t=(t+dp[m%2][i][n-1])%MOD;
        for(int i=1;i<=n-1;++i)
            t=t*i%MOD;
        System.out.println(t);
    }
}
