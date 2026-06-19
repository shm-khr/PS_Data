#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <complex>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define fs first
#define sc second
#define pb push_back
#define show(x) cout << #x << " " << x << endl
int N,x[8],y[8],k,u[100],v[100],gx,gy;
typedef complex<int> P;
typedef vector<P> snake;
map<snake,int> msi;
P dp[6],g;
vector<P> rocks;
int dx[6]={1,0,-1,-1,0,1},dy[6]={-1,-1,0,1,1,0};
namespace std{
	bool operator<(const P& p,const P& q){
		if(p.real()!=q.real()) return p.real()<q.real();
		else return p.imag()<q.imag();
	}
}
bool adj(P p,P q){
	rep(i,6) if(p-q==dp[i]) return true;
	return false;
}
bool check(snake s){
	rep(i,N) rep(j,i-1) if(adj(s[i],s[j])) return false;
	return true;
}
queue<snake> que;
bool tmpok[8][6];
int t;
void dfs(int cnt,int a,snake s){
//	show(cnt);
	if(cnt==N){
		if(check(s)&&msi.count(s)==0){
			if((21-t)*2<abs((g-s[0]).imag())+abs((g-s[0]).real())) return;
			que.push(s);
			msi[s]=t+1;
		}
		return;
	}
	if(((a>>cnt)&1)==0){
		dfs(cnt+1,a,s);
	}else{
		rep(i,6){
			if(!tmpok[cnt][i]) continue;
			P np=s[cnt]+dp[i];
			snake ns=s;
			ns[cnt]=np;
			dfs(cnt+1,a,ns);
		}
	}
}
void showsnake(snake s){
	puts("snake");
	rep(i,N) cout<<s[i]<<endl;
	cout<<endl;
}
int bfs(snake be){
	while(!que.empty()) que.pop();
	msi.clear();
	que.push(be);
	msi[be]=0;
	while(!que.empty()){
		snake s=que.front();
		que.pop();
		if(s[0]==g) return msi[s];
//		showsnake(s);
		rep(i,N){
			rep(j,6){
				tmpok[i][j]=true;
				P np=s[i]+dp[j];
				if(i!=0&&!adj(s[i-1],np)) tmpok[i][j]=false;
				if(i!=N-1&&!adj(s[i+1],np)) tmpok[i][j]=false;
				if(tmpok[i][j]){
					rep(tt,k) if(np==rocks[tt]){tmpok[i][j]=false;break;}
				}
			}
		}
		t=msi[s];
		rep(i,1<<N){
			int a[8];
			rep(j,N) a[j]=(i>>j)&1;
			bool ok=true;
			rep(j,N-1) if(a[j]&&a[j+1]) ok=false;
			if(!ok) continue;
			dfs(0,i,s);
		}
	}
}
int main(){
	rep(i,6) dp[i]=P(dx[i],dy[i]);
	while(true){
		cin>>N;
		if(N==0) break;
		msi.clear();
		rocks.clear();
		rep(i,N) cin>>x[i]>>y[i];
		snake be;
		rep(i,N) be.pb(P(x[i],y[i]));
		cin>>k;
		rep(i,k) cin>>u[i]>>v[i];
		rep(i,k) rocks.pb(P(u[i],v[i]));
		cin>>gx>>gy;
		g=P(gx,gy);
		cout<<bfs(be)<<endl;
	}
}