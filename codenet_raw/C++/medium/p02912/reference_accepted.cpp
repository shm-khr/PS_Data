#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N,M; cin >> N >> M;
    priority_queue<int> A;
    REP(i,N){
        int a; cin >> a;
        A.push(a);
    }

    REP(i,M){
        int a = A.top(); A.pop();
        A.push(a/2);
    }
    
    ll ans = 0;
    while(A.size()>0){
        int a = A.top(); A.pop();
        ans += a;
    }
    cout << ans << endl;
    return 0;
}