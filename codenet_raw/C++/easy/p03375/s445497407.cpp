// In The Name Of God
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define int long long
#define ll long long
#define for2(a,b,c) for(int (a) = (b); (a) < (c); (a)++)
#define setp cout << fixed << setprecision(15)
#define endl "\n"
#define minit(a,b) a = min(a,b)
#define maxit(a,b) a = max(a,b)
#define PII pair<int,int>
#define Vec vector<int>
#define error(x) cerr << #x << " = " << (x) << endl;
#define all(x) (x).begin() , (x).end()

const int maxn = 55;
int dp[maxn][maxn];
int sel[maxn][maxn];
int mod;
int g[maxn][maxn];

int pw(int a,int b){
    if(!b) return 1;
    int x = pw(a,b/2);
    x *= x;
    x %= mod;
    if(b%2) x = (x*a)%mod;
    return x;
}


int pw22(int a,int b){
    if(!b) return 1;
    int x = pw22(a,b/2);
    x *= x;
    x %= mod-1;
    if(b%2) x = (x*a)%(mod-1);
    return x;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n >> mod;
    int N = n;
    for2(i,0,n+1) sel[0][i] = 1;
    for2(i,1,n+1) for2(j,1,n+1) sel[i][j] = (sel[i-1][j-1]+sel[i][j-1])%mod;
    g[0][0] = 1;
    for2(i,1,n+1) for2(k,1,i+1) for2(t,1,i+1) g[i][k] = (g[i][k]+g[i-t][k-1]*sel[t-1][i-1])%mod;
    int ans = 0;
  for2(i,0,N+1){
    n = i;
    int sum = ans;
    ans = 0;
    for2(k,0,n+1) for2(t,0,n+1){
        int x = n-k;
        int p = g[k][t]*sel[k][n];
        p %= mod;
        p = (p*sel[n][N])%mod;
        p = (p*pw(2,t*x))%mod;
        p = (p*(pw(2,  pw22(2,x)   )) )%mod;
       // if(k==1) cout << p << endl;
        if(k%2==0) ans += p;
        else ans -= p;
        ans %= mod;
    }
    //cout << ans << endl;
    if(i%2 == N%2) ans = sum+ans;
    else ans = sum-ans;
   }
    ans %= mod;
    ans += mod;
    cout << (ans)%mod << endl;
  /*  dp[0][0] = 1;
    for2(i,0,n)for2(k,0,i+1) for2(a,0,k+1){
        int j = i-k;
        int t = (sel[a][k])%mod;
        t = (t*dp[a][a])%mod;
        t = (t*)%mod;
    }*/
    return 0;
}
