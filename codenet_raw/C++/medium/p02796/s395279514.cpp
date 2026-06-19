// Created by Nandu Vinodan
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define vi vector<int>
#define pi pair<int, int>
#define INF INT_MAX
#define _INF INT_MIN
#define TC 0

using namespace std;
using ll = long long;

void testcase() {
    int n; cin >> n;
    vector<pair<ll, ll> > v;
    rep (i, 0, n-1) {
    	ll x, l;
    	cin >> x >> l;

    	v.push_back({x-l, x+l});
    }

    sort(v.begin(), v.end());

    int res = 1;
    ll pre = v[0].second;
    for (int i=1; i<v.size(); i++) {
    	if (v[i].first < pre) {
    		continue;
    	}
    	res++;
    	pre = v[i].second;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    if (TC)
        cin>>t;
    while(t--) {
        testcase();
    }
    return 0;
}