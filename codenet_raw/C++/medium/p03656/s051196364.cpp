#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define fo(i,j,l) for(int i=j;i<=l;++i)
#define fd(i,j,l) for(int i=j;i>=l;--i)

using namespace std;
typedef long long ll;
const ll N=81e4,M=N<<1;

int la[N],ne[M],lb[M];
int B[M];

int n,k,oo;

int f1[N],f2[N];
int X[N];
int ans[N];

int r1,r2,R,ok=1;

inline void llb(int a,int b)
{ne[++oo]=la[a]; la[a]=oo; lb[oo]=b;}

inline void dg1(int o)
{
	X[o]=0;
	for(int y=la[o];y;y=ne[y])
	if(f1[lb[y]]==o){
		dg1(lb[y]);
		++X[o];
	}
	X[o]=(X[o]+1)%2;
}

inline void dg2(int o)
{
	for(int y=la[o];y;y=ne[y])
	if(f2[lb[y]-n]==o-n)dg2(lb[y]);
	int k=0;
	for(int y=la[o];y;y=ne[y])
	if(f2[lb[y]-n]==o-n)k++;
	if((k+1)%2!=X[o-n])
	ok=0;
}

inline void dfs(int o)
{
	for(int y=la[o];y;y=ne[y])
	if(!B[y>>1]){
		B[y>>1]=1;
		k=lb[y];
		if(k==n+o||o==k+n){
			if(o>n)ans[k]=-1;
			else ans[o]=1;
		}
		dfs(k);
	}
}

int main()
{
	scanf("%d",&n); R=n+n+n+1;
	fo(i,1,n)scanf("%d",&f1[i]);
	fo(i,1,n)scanf("%d",&f2[i]);
	oo=1;
 	fo(i,1,n)if(f1[i]!=-1)llb(f1[i],i),llb(i,f1[i]);
 	else r1=i;
 	dg1(r1);
 	fo(i,1,n)if(f2[i]!=-1)llb(f2[i]+n,i+n),llb(i+n,f2[i]+n);
 	else r2=i+n;
 	dg2(r2);
 	if(!ok){
 		puts("IMPOSSIBLE");
 		return 0;
	}
	fo(i,1,n)if(X[i]==1)llb(i+n,i),llb(i,i+n);
 	llb(R,r2); llb(r2,R); llb(r1,R); llb(R,r1);
 	dfs(R);
 	puts("POSSIBLE");
 	fo(i,1,n)printf("%d ",ans[i]);
}