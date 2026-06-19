#include <bits/stdc++.h>
#define ll long long
#define INF 999999999
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef pair<int,int>P;
typedef pair<ll,ll>pl;

const int MAX_N = 40;

ll v[MAX_N];
ll w[MAX_N];
vector<pl> x,y;

void solve(int s,int t,vector<pl> &x)
{
	int z = t-s;
	for(int i=0;i<(1<<z);i++){
		P p = P(0,0);
		rep(j,z){
			if(i>>j&1){
				p.first += w[s+j];
				p.second += v[s+j];
			}
		}
		x.push_back(p);
	}
}

int main()
{
	ll n;
	ll lm;
	cin >> n >> lm;
	rep(i,n){
		cin >> v[i] >> w[i];
	}
	solve(0,n/2,x);
	solve(n/2,n,y);
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	ll t=0;
	ll maxv = -(1LL<<60);
	ll ans = 0;
	for(int i=(int)x.size()-1;i>=0;i--){
		P p = x[i]
		while(t < (int)y.size() && p.first+y[t].first <= lm){
			maxv = max(maxv,y[t].second);
			t++;
		}
		ans = max(ans,p.second+maxv);
	}
	cout << ans << "\n";
	return 0;
}