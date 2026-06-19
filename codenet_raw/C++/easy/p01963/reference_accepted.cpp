#include <bits/stdc++.h>

using namespace std;
#define Real double
#define int long long

const int MAXN=100020;
int dp[100020]={0};
namespace SA{
	int rank[MAXN],tmp[MAXN];
	int n,k;
	bool compare_sa(int i,int j){
		if(rank[i]!=rank[j]) return rank[i] <rank[j];
		int ri=(i+k<=n) ?rank[i+k]:-1;
		int rj=(j+k<=n) ?rank[j+k]:-1;
		return ri<rj;
	}

	void createSA(const string &s,int *sa){
		n=s.size();
		for(int i=0;i<=n;i++){
			sa[i]=i;
			rank[i]=i<n?s[i]:-1;
		}
		for(k=1;k<=n;k*=2){
			sort(sa,sa+n+1,compare_sa);
			tmp[sa[0]]=0;
			for(int i=1;i<=n;i++){
				tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
			}
			for(int i=0;i<=n;i++) rank[i]=tmp[i];
		}
	}
}
int N;
vector<int> G[100020];
string e[200020];

int me[100020];
int saiki(int u){
//	cout<<u<<endl;
	if(u==N) return 1;
	if(me[u]>=0)return me[u];
int r=0;
	for(int i=0;i<G[u].size();i++){
		r+=saiki(G[u][i]);
		r %= 1000000007;
	} 
		me[u]=r;
	return r;

}
vector<int> ve;
int sa[MAXN];
signed main() {
	int t;
	cin>>t;

for(int i=0;i<t;i++){
	cin>>e[i];
}

string s;
cin>>s;
N=s.size();
SA::createSA(s,sa);
for(int i=0;i<100020;i++) me[i]=-1;
//for(int i=0;i<=N;i++) cout<<sa[i]<<" ";
//	cout<<endl;

//cout<<"s"<<esss
	int ch[30]={0};
	for(int i=0;i<N;i++) ch[s[i]-'a']++;
bool w=false;
int mo;
		for(int i=0;i<26;i++) if(ch[i]==100000){
			w=true;
			mo=i;
}

if(w){

for(int i=0;i<t;i++){
	for(int j=0;j<30;j++) ch[j]=0;
		for(int j=0;j<e[i].size();j++) ch[e[i][j]-'a']++;
			if(ch[mo]==e[i].size()) ve.push_back(e[i].size());
}

dp[0]=1;
for(int i=1;i<=100000;i++){
	for(int j=0;j<ve.size();j++){
		if(i<ve[j]) continue;
		dp[i] += dp[i-ve[j]];
		dp[i] %= 1000000007;
	}
}
cout<<dp[100000]<<endl;
return 0;

}

for(int i=0;i<t;i++){

int l=e[i].length();
	int ue=N+1;
	int si=0;
	int me;
	while(ue-si>1){
		me=(ue+si)/2;
		if(s.substr(sa[me])<e[i]) si=me;
		else ue=me;
	}
	int hanisi=ue;

	ue=N+1,si=0;
string ee=e[i];
ee[e[i].length()-1]++;
	while(ue-si>1){
		me=(ue+si)/2;
		if(s.substr(sa[me])>=ee) ue=me;
		else si=me;
	}
	int haniue=si;
//cout<<e[i]<<endl;
//cout<<"   "<<hanisi<<" "<<haniue<<endl;1
	for(int j=hanisi;j<=haniue;j++){
		G[sa[j]].push_back(sa[j]+l);
	//	cout<<sa[j]<<" "<<sa[j]+l<<endl;
	}

}

//cout<<"e"<<endl;


cout<<saiki(0)<<endl;
    return 0;

}
