#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int n,q,a[maxn];
ll c[maxn];
void read(int& ret)
{
	ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+ch-'0',ch=getchar();
}
int ask(int u)
{
	ll ret=0;
	for(int i=u;i;i-=(i&(-i))) ret+=c[i];
	return ret;
}
void add(int u,int d)
{
	for(int i=u;i<=n;i+=(i&(-i))) c[i]+=d;
}
int main()
{
	read(n),read(q);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) add(i,a[i]);
	while(q--){
		int type,u,v;
		scanf("%d%d%d",&type,&u,&v);
		if(!type) add(u+1,v);
		else printf("%lld\n",ask(v)-ask(u));
	}
	return 0;
}