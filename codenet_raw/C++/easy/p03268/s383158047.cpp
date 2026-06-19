#pragma GCC optimize ("Ofast","unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define F first
#define S second
#define ALL(a) a.begin(),a.end()
#define MEM(a,b) memset(a,b,sizeof a)
#define Tie ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const ll MOD=998244353;
ll k,n,cnt,ans,dp[2100][2100],p2[2100],C[2100][2100],dp2[2100],st[2100],top;
 
int main()
{Tie
	C[0][0]=1;
	for(int i=1;i<=2000;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	dp[0][0]=1;
	for(int i=1;i<=2001;i++)
	{
		dp[i][0]=1;
		for(int j=1;j<=2001;j++)
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
	}
	for(int i=1;i<=2001;i++)
		dp[0][i]=1;
	p2[0]=1;
	for(int i=1;i<=2001;i++)
		p2[i]=p2[i-1]*2%MOD;
	cin>>k>>n;
	for(int i=2;i<=k+1;i++)
	{
		cnt=(i-1)>>1,ans=0;
		if(i%2&&k-cnt*2>0)
			ans=dp[k-cnt*2][n];
		else if(i%2==0&&k-cnt*2-1>0)
			ans=(dp[k-1-cnt*2][n]+dp[k-1-cnt*2][n-1])%MOD;
		for(int j=1;j<=cnt;j++)
		{
			if(i%2==0)
			{
				n--,k--;
				if(n-j>=0)
					ans=(ans+dp[k-cnt*2+j][n-j]*p2[j]%MOD*C[cnt][j]%MOD)%MOD;
				n++;
				if(n-j>=0)
					ans=(ans+dp[k-cnt*2+j][n-j]*p2[j]%MOD*C[cnt][j]%MOD)%MOD;
				k++;
			}
			else
			{
				if(n-j>=0)
					ans=(ans+dp[k-cnt*2+j][n-j]*p2[j]%MOD*C[cnt][j]%MOD)%MOD;
			}
		}
		cout <<ans<<'\n';
		st[top++]=ans;
	}
	for(int i=top-2;i>-1;i--)
		cout << st[i]<<'\n';
}