#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;

int f[50][10];


long long st(long long k)
{
	long long p;
	while(k)
	{
		k--;
		p*=10;
		p%=1000000007;
	}
	return p;
}

int main()
{
	//freopen("haiku.in","r",stdin);
	//freopen("haiku.out","w",stdout);
	
	int n,x,y,z;memset(f,0,sizeof(f));
	scanf("%d%d%d%d",&n,&x,&y,&z);
	
	for(int i=1;i<=max(x,max(y,z));i++)
	f[1][i]=1;
	for(int i=2;i<=n;i++)
	for(int j=i;j<=8;j++)
	f[i][j]=f[i-1][j-1]+f[i][j-1];
	/*
	for(int i=1;i<=5;i++)
	{for(int j=1;j<=max(x,max(y,z));j++)
	printf("%d ",f[i][j]);
	printf("\n");}
	*/
	int total=0;
	int ans;
	for(int i=0;i<=n-3;i++)
	for(int j=i+1;j<=n-2;j++)
	for(int k=j+1;k<=n-1;k++)
	for(int l=k+1;l<=n;l++)
	{
		ans=0;
		ans+=f[j-i][x]*f[k-j][y]*f[l-k][z];
		ans=ans%(1000000007);
		if(i>0)
		ans=ans*st(i)%1000000007;
		if(n-l>0)
		ans=ans*st(n-l)%1000000007;
		total+=ans;
	}
	printf("%d",total);
	
	return 0;
}