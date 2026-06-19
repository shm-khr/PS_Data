#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long dp[2300];
char str[110][210];
typedef unsigned long long wolf;
wolf hash[110][210];
int len[110];
long long INF=1100000000000000000LL;
char ret[2300];
long long dp2[2300];
long long mod=1000000007;
wolf th[2300];
int main(){
	int a,b;
	long long c;
	scanf("%d%d%lld",&a,&b,&c);
	c--;
	for(int i=0;i<a;i++)scanf("%s",str[i]);
	for(int i=0;i<a;i++){
		hash[i][0]=str[i][0];
		for(int j=1;str[i][j];j++)hash[i][j]=hash[i][j-1]*mod+str[i][j];
	}
	for(int i=0;i<a;i++)len[i]=strlen(str[i]);
	dp[0]=1;
	for(int i=0;i<b;i++){
		for(int j=0;j<a;j++){
			dp[i+len[j]]=min(INF,dp[i+len[j]]+dp[i]);
		}
	}
	dp2[0]=1;
	if(dp[b]<=c){
		printf("-\n");return 0;
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<26;j++){
			long long val=0;
			wolf ks=1;
			wolf now=j+'a';
			for(int k=0;k<min(210,i+1);k++){
				if(k){
					ks*=mod;
					now+=ks*ret[i-k];
				}
				th[k]=now;
			}
			for(int k=0;k<a;k++){
				for(int l=max(0,i-len[k]+1);l<=i;l++){
					if(!dp2[l])continue;
					int n=i-l;
					if(th[n]==hash[k][n]){
						if((INF-val)/dp2[l]<dp[b-len[k]-l])val=INF;
						else val+=dp2[l]*dp[b-len[k]-l];
					}
				}
			}
			//if(val){
		//		for(int k=0;k<20;k++)printf("%llu ",th[k]);
		//		printf("\n");
		//		printf("%d %d: %lld %lld\n",i,j,val,c);
		//	}
			if(c<val){
				for(int k=0;k<a;k++){
					if(th[len[k]-1]==hash[k][len[k]-1]){
						dp2[i+1]=min(INF,dp2[i+1]+dp2[i+1-len[k]]);
					}
				}
				ret[i]='a'+j;
				break;
			}else c-=val;
		}
	}
	printf("%s\n",ret);
}