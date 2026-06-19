# include <bits/stdc++.h>
# define rep(i, n) for (ll i = 0; i < (n); i++)
# define reps(i, n) for (ll i = 1; i <= (n); i++)
# define foreps(i, m, n) for (ll i = (m); i < (n); i++)
# define len(x) ((int)(x).size())
# define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

ll N;

ll solve(vector<ll> a) {
    ll res = 1e18;
    for (ll i = a[0]; i <= a[N - 1]; i++) {
        ll rem = 0;
        rep(j, N) rem += pow(a[j] - i, 2);
        res = min(res, rem);
    }
    return res;
}

int main() {
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));
    
    cout << solve(A) << endl;
}