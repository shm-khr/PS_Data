#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N,M,K,L,R,H,W;

constexpr long long int MOD=1000000007;
//constexpr  int MOD=1000000007;
//constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>M;
	vector<long long int>v(N);
	for(auto &i:v)cin>>i;
	map<int,int>mp;
	int ans=0;
	vector<int>er(N,-1);
	if(M-1<N)er[M-1]=0;
	mp[0]++;
	for(int i=0;i<N;i++){
		if(er[i]!=-1)mp[er[i]]--;
		v[i]--;
		if(i)v[i]+=v[i-1];
		v[i]%=M;
		ans+=mp[v[i]];
		mp[v[i]]++;
		if(i+M+0<N)er[i+M+0]=v[i];
	}
	cout<<ans<<endl;
}