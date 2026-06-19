#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ans,a[3001],b[3001],s[3001][3001];
inline int read()
{
    int sum=0,x=1;
    char ch=getchar();
    while (!isdigit(ch))
	{
        if (ch=='-')
		  x=-1;
        ch=getchar();
    }
    while (isdigit(ch))
	{
        sum=(sum<<1)+(sum<<3)+(ch^'0');
        ch=getchar();
    }
    return sum*x;
}
inline void write(int x)
{
    if (x<0)
	{
        putchar('-');
        x=-x;
    }  
    if (x>9)
      write(x/10);
    putchar(x%10+'0');
}
inline int sr(int x,int y)
{
	return (ll)a[x]*b[y]%m*b[x-y]%m;
}
inline int power(int x,int y,int z)
{
    int ss=1;
    while (y)
    {
        if (y%2==1)
		  ss=(ll)ss*x%z;
        x=(ll)x*x%z;
		y>>=1;
    }
    return ss;
}
signed main()
{
    n=read();m=read();
    a[0]=a[1]=b[0]=b[1]=1;
    for (register int i=2;i<=n;++i)
	{
		a[i]=(ll)a[i-1]*i%m;
	    b[i]=(ll)(m-m/i)*b[m%i]%m;
	}
    for (register int i=2;i<=n;++i)
	  b[i]=(ll)b[i-1]*b[i]%m;
    s[0][0]=1;
    for (register int i=1;i<=n+1;++i)
      for (register int j=1;j<=i;++j)
        (s[i][j]=s[i-1][j-1]+(ll)s[i-1][j]*j%m)%=m;
    for (register int i=0;i<=n;++i)
    {
        int ss=0;
        for (register int j=0;j<=i;++j)
          (ss+=(ll)power(power(2,n-i,m),j,m)*s[i+1][j+1]%m)%=m;
        ss=(ll)ss*power(2,power(2,n-i,m-1),m)%m*sr(n,i)%m;
        if (i%2==1)
		  (ans-=ss)%=m;else
		  (ans+=ss)%=m;
    }
    write((ans+m)%m);
    return 0;
}