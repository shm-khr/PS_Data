#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
char str[600][20];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int num[600][20];
long long mod=1000000007;
long long pow(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
typedef map<int,long long> vec;
typedef vector<vec> mat;
long long det(mat A){
	int n=A.size();
	long long val=1;
	for(int i=0;i<n;i++){
		int at=-1;
		for(int j=i;j<n;j++){
			if(A[j].count(i)&&A[j][i]){
				at=j;break;
			}
		}
		if(!~at)return 0;
		if(at!=i){
			swap(A[at],A[i]);
			val=(mod-val);
		}
		val=val*A[i][i]%mod;
		long long t=pow(A[i][i],mod-2);
		for(map<int,long long>::iterator it=A[i].begin();it!=A[i].end();it++){
			A[i][(*it).first]=(*it).second*t%mod;
		}
		for(int j=i+1;j<n;j++){
			if(A[j].count(i)&&A[j][i]){
				long long div=mod-A[j][i];
				for(map<int,long long>::iterator it=A[i].begin();it!=A[i].end();it++){
					if((*it).second==0){continue;}
					if(!A[j].count((*it).first))A[j][(*it).first]=(*it).second*div%mod;
					else A[j][(*it).first]=(A[j][(*it).first]+(*it).second*div)%mod;
				}
			}
		}
	}
	for(int i=0;i<n;i++)val=val*A[i][i]%mod;
	return val;
}
int main(){
	int a,b;
	int T=0;
	while(scanf("%d%d",&a,&b),a){
		T++;
		for(int i=0;i<a;i++)scanf("%s",str[i]);
		int at=0;
		for(int i=0;i<a;i++)for(int j=0;j<b;j++){
			num[i][j]=-1;
		}
		for(int i=0;i<a;i++)for(int j=0;j<b;j++){
			if(str[i][j]!='#')num[i][j]=at++;
		}
		mat A(at-1);
		for(int i=0;i<a;i++)for(int j=0;j<b;j++){
			if(str[i][j]!='#'){
				int deg=0;
				for(int k=0;k<4;k++){
					if(0<=i+dx[k]&&i+dx[k]<a&&0<=j+dy[k]&&j+dy[k]<b&&~num[i+dx[k]][j+dy[k]]){
						deg++;
						if(num[i][j]<at-1&&num[i+dx[k]][j+dy[k]]<at-1){
							A[num[i][j]][num[i+dx[k]][j+dy[k]]]=mod-1;
						}
					}
				}
				if(num[i][j]<at-1)A[num[i][j]][num[i][j]]=deg;
			}
		}
	//	for(int i=0;i<at-1;i++,printf("\n"))for(int j=0;j<at-1;j++)printf("%lld ",A[i][j]);
		printf("Case %d: %lld\n",T,det(A));
	}
}