#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define INF (ll)(1e18)
#define inf 0x7fffffff
#define inff 100000
#define ff first
#define ss second
#define sz(x) ((int) (x).size())
#define fast cin.sync_with_stdio(0);cin.tie(0)
#define rep(i,N) for(int i = 0;i < N;i++)
#define frep(i,a,b) for(int i = a;i <= b;i++)
#define pii pair<int , int>
#define pll pair<ll , ll>
#define vii vector<int>
#define vpii vector< pii >
#define fill(A,v) memset(A,v,sizeof(A))
#define setbits(x) __builtin_popcountll(x)
#define print(A,j,k) for(int ii=j;ii<k;ii++)cout<<A[ii]<<" ";cout<<"\n"
#define all(x) (x).begin(), (x).end()
#define gcd __gcd
#define SQRT 350
#define CASES int t;cin>>t;while(t--)
#define FILE freopen("inp.txt" , "r" , stdin);
#define ld long double

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

vii V[26];

int main(int argc, char const *argv[])
{
	fast;

	string s;
	cin >> s;

	rep(i , s.size()) {
		int v = s[i] - 'a';
		V[v].pb(i);
	}

	for(int i = 0;i < 26;i++) {
		if (V[i].size() == 0)
			continue;
		int prev = V[i][0];
		int curr;
		for(int j = 1;j < V[i].size();i++) {
			
			curr = V[i][j];
			if (curr == prev + 2) {
				cout << prev + 1 << ' ' << curr + 1 << '\n';
				return 0;
			}

		}
	}

	cout << "-1 -1\n";

	return 0;
}