#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
//問題文および制約はちゃんと確認しよう！
//サイズは10^5じゃなくて2×10^5とかかもしれないし、重要な制約・条件を見落としているかも
//とりあえずサンプルを読んでから解法を考えよう？
lint dp[315][2];
lint num[610][315];
lint d2[315];
lint mo=1000000007;
int n;
int in(int l,int h,int a){
	if(l<=a && a<h) return 1;
	if(l<=a+n*2 && a+n*2<h) return 1;
	return 0;
}
int a[315],b[315];
int main()
{
	int K;
	cin>>n>>K;
	rep(i,n){
		cin>>a[i]>>b[i];a[i]--;b[i]--;
		if(a[i]>b[i]) swap(a[i],b[i]);
	}
	d2[1]=1;
	REP(i,1,310) d2[i+1]=d2[i]*(i*2+1)%mo;
	memset(num,0,sizeof(num));
	rep(i,2*n) REP(j,1,n){
		int p=j;
		rep(k,K){
			int x=in(i,i+j*2,a[k]),y=in(i,i+j*2,b[k]);
			//if(i==1 && j==2) cout<<a[k]<<' '<<b[k]<<' '<<x<<' '<<y<<endl;
			if(x+y==1) p=-1;
			if(x+y==2) p--;
		}
		if(p<0) num[i][j]=0;
		else num[i][j]=d2[p];
		//cout<<i<<' '<<j<<' '<<num[i][j]<<endl;
	}
	//cout<<num[1][2]<<endl;
	lint out=d2[n-K];
	rep(i,n*2){
		memset(dp,0,sizeof(dp));dp[0][0]=1;
		rep(j,n) REP(k,j+1,n+1) rep(l,2){
			if((i/2)+j>=n || k-j>=n) continue;
			//if(i==5) cout<<j<<k<<endl;
			dp[k][1-l]+=dp[j][l]*num[(i+j*2)%(2*n)][k-j];
			dp[k][1-l]%=mo;
		}
		//cout<<i<<' '<<dp[n][0]<<' '<<dp[n][1]<<endl;
		out+=dp[n][0];out-=dp[n][1];
		out%=mo;
	}
	out%=mo;out+=mo;out%=mo;
	cout<<out<<endl;
}
