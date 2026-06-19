#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<map>
typedef long long ll;
using namespace std;
#define INF 0x3f3f3f3f
int r=100000;
int a[10005],b[10005],c[10005],d[10005],e[10005];
int main()
{
	int n,i,j,t,k,l,o,m,q,w;
	cin>>m>>t>>k;
	for(i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=t;i++)
	{
		cin>>b[i];
	}
	for(i=1;i<=k;i++)
	{
		cin>>c[i]>>d[i]>>e[i];
	r=min(r,a[c[i]]+b[d[i]]-e[i]);
	}
	sort(a+1,a+1+m);
	sort(b+1,b+1+t);
	r=min(a[1]+b[1],r);
	cout<<r;
	
 } 