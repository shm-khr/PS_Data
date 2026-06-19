#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const int maxn=1E5+5; 
ll n,sum,pre[maxn];
struct pt
{
	ll x,y;
	bool operator<(const pt&A)const
	{
		return max(x,y)<max(A.x,A.y);
	}
}a[maxn];
inline int get(int pos)
{
	int l=0,r=n,mid;// !!!!!!!!!!!!!!!
	int d=max(a[pos].x,a[pos].y);
	while(l<r)
	{
		mid=(l+r+1)>>1;
		ll s=pre[mid]-(mid>=pos?d:0);
		if(s<=sum)
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
ll gcd(ll x,ll y)
{
	if(y==0)
		return x;
	return x%y==0?y:gcd(y,x%y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].x>>a[i].y;
		sum+=max((ll)0,a[i].y-a[i].x);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		pre[i]=pre[i-1]+max(a[i].x,a[i].y);
	ll ax=0,ay=1;
	for(int i=1;i<=n;++i)
	{
		int pos=get(i);
		ll s=sum-pre[pos];
		if(pos>=i)
			--pos,s+=max(a[i].x,a[i].y);
		if(a[i].y>a[i].x)
			s-=a[i].y-a[i].x;//!!!!!!!!!!!!! 
		ll x=(ll)pos*a[i].y+min(s+a[i].y-a[i].x,a[i].y);
		ll y=n*a[i].y;
		if(x<=0)
			continue;
		ll z=gcd(x,y);
		x/=z,y/=z;
		if((ld)ay*x>(ld)y*ax)
			ax=x,ay=y;
	}
	cout<<ax<<" "<<ay<<endl;
	return 0;
}
