#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int ans, N;
ll X[100005], L[100005];


int main(void) {
    scanf("%d", &N);
    rep(i, 0, N) scanf("%lld %lld", &X[i], &L[i]);

    vector<pair<ll, ll> > p;
    rep(i, 0, N) {
        p.pb(mp(X[i]-L[i], X[i]+L[i]));
    }
    sort(p.bg, p.en);

    int i = 0;
    while (i < N) {
        ll s = p[i].first;
        ll e = p[i].second;
        ans++;
        while ( i < N && p[i].first<e) i++;
    }

    
   

  
    printf("%d\n", ans);

	return 0;
}
