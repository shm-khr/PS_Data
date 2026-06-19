#include<bits/stdc++.h>
using namespace std;
const int Max=1e5+1;
const long long Mod=1e9+7;
int cnt=0,M;
long long P[Max*3+10]={},inv[Max*3+10]={},Pow[Max*3+10]={};
inline long long C(int n,int m){return P[n]*inv[n-m]%Mod*inv[m]%Mod;}
int main(){
	P[0]=P[1]=1; for(int i=2;i<=Max*3;i++) P[i]=i*P[i-1],P[i]%=Mod;
	inv[0]=inv[1]=1; for(int i=2;i<=Max*3;i++) inv[i]=inv[Mod%i]*(Mod-Mod/i)%Mod;
	for(int i=2;i<=Max*3;i++) inv[i]=inv[i]*inv[i-1]%Mod;
	Pow[0]=1; for(int i=1;i<=Max*3;i++) Pow[i]=Pow[i-1]*3%Mod;
	int N,M,Q; scanf("%d%d%d",&N,&M,&Q);
	long long Ans=0,Sum1=0,Sum2=0;
	for(int i=N;i<=N+M+Q+3-1;i++){
		if(i==N){
			for(int j=0;j<i-N-Q;i++) Sum1+=C(i-N,j);
		    for(int j=max(i-N-Q,0);j<=min(M,i-N);j++) Sum2+=C(i-N,j);
		}else{
            if(i-N-Q-2>=0) Sum1=(Sum1*2%Mod-C(i-1-N,i-N-Q-2)+Mod)%Mod;
            Sum2=(Sum2*2%Mod-C(i-1-N,min(M,i-1-N))+Mod)%Mod;
			if(max(i-N-Q,0)>max(i-N-Q-1,0)) Sum1+=C(i-N,i-N-Q-1),Sum1%=Mod;
			if(min(M,i-N-1)<min(M,i-N)) Sum2+=C(i-N,min(M,i-N)),Sum2%=Mod;
		}
		Ans+=C(i-1,N-1)*Pow[N+M+Q-i]%Mod*(Sum2-Sum1+Mod)%Mod,Ans%=Mod;
//		for(int j=max(i-N-Q,0);j<=min(M,i-N);j++)
//		 Ans+=C(i-1,N-1)*C(i-N,j)%Mod*Pow[N+M+Q-i]%Mod,Ans%=Mod;  
	}
	printf("%lld\n",Ans);
	return 0;
}