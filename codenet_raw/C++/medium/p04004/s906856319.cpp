#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=3e3+7;
ll C[maxn][maxn];
void db()
{
	for(int i=0;i<maxn;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
}
int main()
{
	db();
	int n,m,k;
	cin>>n>>m>>k;
	ll ans=0;
	for(int t=n;t<=n+m+k;t++)
	{
		ll cur=0;
		for(int i=max(0,t-n-k);i<=min(m,t-n);i++)
			cur=(cur+C[t-n][i])%mod;
		ans=(ans+cur*C[t-1][n-1]%mod*quick(3,n+m+k-t)%mod)%mod;
	}
	cout<<ans<<endl;
}
