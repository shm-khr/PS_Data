#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll f[1<<6][305],ans;
int n,C,L[15];
int main(){
	cin>>n>>C;
	for(int i=0;i<n;++i)cin>>L[i];
	sort(L,L+n);
	int tot=0,t=(1<<n-1)-1;
	do{
		++tot;memset(f,0,sizeof(f));
		f[0][n*L[n-1]]=1;
		for(int i=1;i<=n*C;++i){
			if(i%n){
				int id=i%n-1,t=min(i+L[id]*n,n*C);
				for(int s=0;s<=t;++s){
					if(!(s>>id&1)){
						for(int k=i;k<=n*C;++k){
							f[s|(1<<id)][max(t,k)]+=f[s][k];
						}
					}
				}
			}
		}
		ans+=f[t][n*C];
	}while(next_permutation(L,L+n-1));
	printf("%.16lf\n",1.0*ans/tot/pow(C,n-1));
	return 0;
}