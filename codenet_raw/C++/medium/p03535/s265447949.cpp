#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<queue>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define inf 1e17
#define ll long long
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')	{if(c=='-')	f=-1;	c=getchar();}
    while(c>='0'&&c<='9')	t=t*10+c-'0',c=getchar();
    return t*f;
}
inline void write(ll x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
int ans,rev[101],cnt[101],n,d[101],t[101],tim;
inline void check()
{
	For(i,1,n)	if(d[i]!=0)if(rev[i])	t[i]=d[i];else t[i]=24-d[i];
	int tans=1e8;
	For(i,1,n)
		For(j,i+1,n)	tans=min(tans,min(24-abs(t[i]-t[j]),abs(t[i]-t[j])));
	ans=max(tans,ans);
	tim++;
	if(tim*n*n>=100000000)	{writeln(ans);exit(0);}
}
inline void dfs(int x)
{
	if(x==n+1)	{check();return;}
	int t=rand()&1;
	if(t==1)	{rev[x]=0;dfs(x+1);rev[x]=1;dfs(x+1);rev[x]=0;}
	else 		{rev[x]=1;dfs(x+1);rev[x]=0;dfs(x+1);rev[x]=0;}
}
int main()
{
	srand(time(0));
	n=read();
	For(i,1,n)	d[i]=read(),cnt[d[i]]++;
	d[n+1]=0;n++;cnt[0]++;
	sort(d+1,d+n+1);
	if(n>25){puts("0");return 0;}
	dfs(1);
	writeln(ans);
}