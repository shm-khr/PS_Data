//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
#define N 3010
int mdn;
void upd(int &x,int y){x+=x+y>=mdn?y-mdn:y;}
int ksm(int bs,int mi)
{
	int ans=1;
	while(mi)
	{
		if(mi&1)	ans=1ll*ans*bs%mdn;
		bs=1ll*bs*bs%mdn; mi>>=1;
	}
	return ans;
}
int f[N][N],n,c[N][N];
void init()
{
	f[0][0]=1; f[1][1]=1; c[0][0]=c[1][0]=c[1][1]=1;
	for(int i=2;i<=n+1;c[i][0]=1,i++)	for(int j=1;j<=n+1;j++)
		f[i][j]=(f[i-1][j-1]+1ll*f[i-1][j]*j%mdn)%mdn,
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%mdn;
}
int F(int x)
{
	int ans=0,k=ksm(2,n-x),tmp=1,w=ksm(2,k);
	for(int i=0;i<=x;i++)	upd(ans,1ll*tmp*f[x+1][i+1]%mdn*w%mdn),tmp=1ll*tmp*k%mdn;
	return ans;
}
int main()
{
	n=read(); mdn=read(); init(); int ans=0;
	for(int i=0;i<=n;i++)	upd(ans,1ll*(i&1?mdn-1:1)*F(i)%mdn*c[n][i]%mdn);
	printf("%d\n",ans);
	return 0;
}