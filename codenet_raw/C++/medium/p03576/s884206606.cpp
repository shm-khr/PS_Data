#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define REP(i, n) for(i=0; i<n; i++)
#define REPR(i, n) for(i=n; i>=0; i--)
#define FOR(i, m, n) for(i=m; i<n; i++)
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 1<<30
#define MOD 1000000007LL
#define MAX 100005
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PA;
typedef priority_queue<ll> PQ;
typedef pair<double, double> doup;
typedef vector<ll> vec;
typedef vector<vec> mat;

int main() {
    ll N, K;
    cin >> N >> K;
    ll x[51], y[51], i, j, k, l, p;
    ll num;
    for(i=0; i<N; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x, x+N);
    sort(y, y+N);
    
    ll ans=(x[N-1]-x[0])*(y[N-1]-y[0]);
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            for(k=0; k<N; k++) {
                for(l=0; l<N; l++) {
                    num=0;
                    if(x[i]>=x[j] || y[k]>=y[l]) continue;
                    for(p=0; p<N; p++) {
                        if(x[i]<=x[p] && x[p]<=x[j] && y[k]<=y[p] && y[p]<=y[l])
                            num++;
                    }
                    if(num>=K)
                        ans=min(ans, 1LL*(x[j]-x[i])*(y[l]-y[k]));
                }
            }
        }
    }
    
    cout << ans << endl;
}
