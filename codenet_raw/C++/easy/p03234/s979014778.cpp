#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10ll+ch-'0';ch=getchar();}
	return x*f;
}
inline ll fast_pow(ll a,ll b,ll p){
    ll t=1;a%=p;
    while (b){
        if (b&1) t=t*a%p;
        b>>=1;a=a*a%p;
    }
    return t;
}
ll n,K,g[1010],a[1010],dp[1010][1010],_;
signed main(){
	n=read()*2,K=read();
	for (int i=1;i<=K;i++){
		int x=read(),y=read();
		a[x]=y,a[y]=x;
	}
	g[0]=1;
	for (ll i=2;i<=n;i+=2) g[i]=g[i-2]*(i-1)%ljc;
	for (int len=2;len<=n;len+=2){
		for (int i=1;i+len-1<=n;i++){
			int j=i+len-1,col=len;
			bool flag=1;
			for (int k=i;k<=j;k++){
				if (a[k]&&(a[k]<i||a[k]>j)) flag=0;
				col-=(a[k]>0);
			}
			if (!flag) continue;
			dp[i][j]=g[col];
			for (int k=j,d=0;k>i;k--){
				d+=(!a[k]);
				dp[i][j]=(dp[i][j]-dp[i][k-1]*g[d]%ljc+ljc)%ljc;
			}
			_=(_+dp[i][j]*g[n-2*K-col]%ljc)%ljc;
		}
	}
	cout<<_;
	return 0;
}