#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int C=55;
int n,c;
int a[10];
double dp[C][10][1<<5];
int main(){
	n=read(),c=read();
	For(i,1,n)
		a[i]=read();
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	double cnt=0,tot=0;
	do {
		For(k,0,C-1)
			For(t,1,n)
				For(j,0,31)
					dp[k][t][j]=0;
		dp[0][1][0]=1;
		For(i,0,c-1)
			For(t,2,n){
				For(j,0,c-1)
					For(k,1,n){
						if (j+a[k]<i)
							continue;
						if (k==t||(j+a[k]==i&&t>k))
							continue;
						For(s,0,(1<<(n-1))-1){
							if (s>>(t-2)&1)
								continue;
							if (dp[j][k][s]==0)
								continue;
//							printf("%d,%d:dp[%d][%d][%d] = %lf",i,t,j,k,s,dp[j][k][s]);
							int _s=s|1<<(t-2);
							if (j+a[k]>i+a[t]||(j+a[k]==i+a[t]&&k>t)){
								dp[j][k][_s]+=dp[j][k][s];
//								printf("->dp[%d][%d][%d]\n",j,k,_s);
							}
							else {
								dp[i][t][_s]+=dp[j][k][s];
//								printf("->dp[%d][%d][%d]\n",i,t,_s);
							}
						}
					}
			}
		double tmp=0;
//		For(j,0,c-1)
//			For(k,1,n)
//				printf("dp[%d][%d] = %lf\n",j,k,dp[j][k][(1<<(n-1))-1]);
		For(j,0,c-1)
			For(k,1,n)
				if (j+a[k]>=c)
					tmp+=dp[j][k][(1<<(n-1))-1];
		tot+=tmp/pow(c,n-1);
		cnt+=1.0;
	} while (next_permutation(a+2,a+n+1));
	printf("%.12lf\n",tot/cnt);
	return 0;
}