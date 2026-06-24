#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;
const int maxn=200005;
const int maxt=4000000;
const int maxv=1000000000;
const int mod=1000000007;
struct line
{
	int k,b;
};
line pre[maxn];
int n,i,j,nt,rt;
int l[maxn],r[maxn],p[maxn];
int minval[maxt],maxval[maxt];
int lch[maxt],rch[maxt];
bool cmp(line x,line y)
{
	if (x.k!=y.k)
		return x.k<y.k;
	return x.b<y.b;
}
int f[maxn];
void ins(int &u,int l,int r,int p,int v)
{
	if (p<l||p>r)
		return;
	if (u==0)
	{
		u=++nt;
		assert(u<maxt);
		minval[u]=maxv;
	}
	if (v<minval[u])
		minval[u]=v;
	if (v>maxval[u])
		maxval[u]=v;
	if (l==r)
		return;
	int mid=(l+r)>>1;
	if (p<=mid)
		ins(lch[u],l,mid,p,v);
	else
		ins(rch[u],mid+1,r,p,v);
}
int qrymax(int u,int l,int r,int ql,int qr)
{
	if (qr<l||r<ql)
		return 0;
	if (u==0)
		return 0;
	if (ql<=l&&r<=qr)
		return maxval[u];
	int mid=(l+r)>>1;
	return max(qrymax(lch[u],l,mid,ql,qr),qrymax(rch[u],mid+1,r,ql,qr));
}
int qrymin(int u,int l,int r,int ql,int qr)
{
	if (qr<l||r<ql)
		return maxv;
	if (u==0)
		return maxv;
	if (ql<=l&&r<=qr)
		return minval[u];
	int mid=(l+r)>>1;
	return min(qrymin(lch[u],l,mid,ql,qr),qrymin(rch[u],mid+1,r,ql,qr));
}
bool cmp2(int x,int y)
{
	return r[x]<r[y];
}
void plus(int p,int v)
{
	assert(v>=0);
	assert(v<mod);
	p++;
	for (int i=p;i<=n+1;i+=(i&-i))
		f[i]=(f[i]+v)%mod;
}
int query(int p)
{
	p++;
	int ret=0;
	for (int i=p;i;i-=(i&-i))
		ret=(ret+f[i])%mod;
	return ret;
}
int sum(int l,int r)
{
	return (query(r)+mod-query(l-1))%mod;
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d%d",&pre[i].b,&pre[i].k);
	sort(pre+1,pre+n+1,cmp);
	for (i=1;i<=n;i++)
		ins(rt,1,maxv,pre[i].b,i);
	for (i=1;i<=n;i++)
	{
		l[i]=qrymin(rt,1,maxv,pre[i].b,maxv);
		assert(l[i]>0);
		r[i]=qrymax(rt,1,maxv,1,pre[i].b);
		assert(r[i]<maxv);
		if (i<l[i])
			l[i]=i;
		if (i>r[i])
			r[i]=i;
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp2);
	plus(0,1);
	for (i=1;i<=n;i++)
		plus(r[p[i]],sum(l[p[i]]-1,r[p[i]]));
	printf("%d\n",sum(n,n));
	return 0;
}