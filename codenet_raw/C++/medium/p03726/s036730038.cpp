#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mt make_tuple
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<string,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef tuple<int,int,int> tp;
typedef vector<tp> vt;
typedef vector<vd> vvd;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-7;
const int inf=1e9;
const ll INF=2e18;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
	int n;
	cin>>n;
	vvi G(n);
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	vi co(n);
	rep(i,n)if(G[i].size()==1)co[G[i][0]]++;
	bool h=false;
	rep(i,n)if(co[i]>1)h=true;
	rep(i,n)if(co[i]==0){
		int c=0;
		rep(j,G[i].size())if(co[G[i][j]])c++;
		if(c>1&&c==G[i].size())h=true;
	}
	if(h)cout<<"First"<<endl;
	else cout<<"Second"<<endl;
}
/*
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vs in(n);
	rep(i,n)cin>>in[i];
	int sx,sy;
	rep(i,n)rep(j,m)if(in[i][j]=='S'){
		sx=i,sy=j;
		in[i][j]='.';
	}
	int dp[
}
//*/




