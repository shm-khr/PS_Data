#include<cstdio>
using namespace std;
const int MAXN=200005;
int s[MAXN]={0};
int main()
{
	int a,n,k,i,j,ans=0,m,mid;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		m=a%k;
		s[i]=(s[i-1]+m)%k;
		if(m==1) ans++;
		for(j=1;j<i;j++)
		{
			mid=s[i]-s[j-1];
			if(mid<0) mid+=k;
			if(mid==i-j+1) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}