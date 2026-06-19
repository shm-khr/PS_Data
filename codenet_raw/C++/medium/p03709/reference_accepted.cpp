#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define mod 1000000007
#define ll long long
ll n,b[2000005],tot,id[2000005],l[2000005],r[2000005],f[2000005],sum[2000005],le;
struct l1{
	ll x,v;
}s[2000005];
ll add(ll x){
	return x>=mod?x-mod:x;
}
ll cmp(l1 a,l1 b){
	return a.v<b.v;
}
int main(){
//	freopen("random.in","r",stdin);
//	freopen("count.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld",&s[i].x,&s[i].v);
		b[++tot]=s[i].x;
	}
	sort(s+1,s+n+1,cmp);
	sort(b+1,b+tot+1);
	for(ll i=1;i<=n;i++){
		s[i].x=lower_bound(b+1,b+tot+1,s[i].x)-b;
		id[s[i].x]=i;
	}
	for(ll i=1;i<=n;i++) r[i]=max(r[i-1],id[i]);
	l[n]=id[n];
	for(ll i=n-1;i>=1;i--) l[i]=min(l[i+1],id[i]);
	f[0]=sum[0]=1;le=0;
	for(ll i=1;i<=n;i++){
		while(le<r[i]) le++,sum[le]=sum[le-1];
		sum[le]=(sum[le]+sum[le]-((l[i]==1)?0:sum[l[i]-2])+mod)%mod;
	}
	printf("%lld",(sum[n]-sum[n-1]+mod)%mod);
}