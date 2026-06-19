#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxSize=2000;
vector<int>g[maxSize];
int dp[maxSize][maxSize];
int dp2[maxSize][maxSize];
int K;
int v[2100];
void calc(int a,int b){
	v[a]=1;
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i])continue;
		calc(g[a][i],a);
		v[a]+=v[g[a][i]];
	}
	for(int i=0;i<=g[a].size();i++)for(int j=0;j<=K;j++)dp2[i][j]=-999999;
	dp2[0][0]=1;
	int sz=0;
	int at=0;
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i])continue;
		for(int j=0;j<=sz;j++){
			dp2[at+1][j]=max(dp2[at+1][j],dp2[at][j]);
			for(int k=0;j+k+1<=K;k++){
				dp2[at+1][max(j,k+1)]=max(dp2[at+1][max(j,k+1)],dp2[at][j]+dp[g[a][i]][k]);
			}
		}
		at++;
		sz+=v[g[a][i]];
	}
	for(int i=0;i<=K;i++)dp[a][i]=dp2[at][i];
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	K=b;
	for(int i=0;i<a-1;i++){
		int p,q;scanf("%d%d",&p,&q);
		p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	calc(0,-1);
	int ret=0;
	for(int i=0;i<a;i++)for(int j=0;j<=b;j++)
		ret=max(ret,dp[i][j]);
	printf("%d\n",a-ret);
}
