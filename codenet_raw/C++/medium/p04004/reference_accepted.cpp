#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N=1e7+100,mod=1e9+7;
int n,m,K,fac[N],inv[N],ans;
int qpow(int x,int y) {
	int res=1;
	while(y) {
		if(y&1) res=(LL)res*x%mod;
		x=(LL)x*x%mod, y>>=1;
	}
	return res;
}
int C(int x,int y) {
	if(y<0 || x<y) return 0;
	return (LL)fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void init(int mx) {
	fac[0]=1;
	for(int i=1;i<=mx;++i) fac[i]=(LL)fac[i-1]*i%mod;
	inv[mx]=qpow(fac[mx],mod-2);
	for(int i=mx-1;~i;--i) inv[i]=(LL)inv[i+1]*(i+1)%mod;
}
int main() {
	scanf("%d%d%d",&n,&m,&K);
	init(n+m+K);
	int tms=qpow(3,m+K),iv=qpow(3,mod-2);
	for(int t=0,s=1;t<=m+K;++t,tms=(LL)tms*iv%mod) {
		if(t) s=(2ll*s+mod-C(t-1,K)+mod-C(t-1,t-1-m))%mod;
		else s=1;
		ans=(ans+(LL)C(t+n-1,n-1)*s%mod*tms%mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}