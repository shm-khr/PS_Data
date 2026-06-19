#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 105;
vector<int> a[maxn];

void e(int a1, int a2, int a3, int a4) {
    a[a1].push_back(a2);
    a[a2].push_back(a3);
    a[a3].push_back(a4);
    a[a4].push_back(a1);
}

void E(int a1, int a2, int a3, int a4) {
    e(a4, a3, a2, a1);
}

void build(int l, int r) {
    int n = r - l;
    if (n % 2) {
        for (int i = l; i < r; ++i) {
            forn (step, n - 1)
                a[i].push_back((i + step + 1 - l) % n + l);
        }
        return;
    }

    //if (n == 8) {
        //e(0, 1, 4, 5);
        //e(2, 3, 6, 7);
        //E(0, 1, 4, 5);
        //E(2, 3, 6, 7);

        //e(1, 2, 5, 6);
        //e(0, 3, 4, 7);
        //E(1, 2, 5, 6);
        //E(0, 3, 4, 7);

        //e(1, 5, 3, 7);
        //e(0, 2, 6, 4);
        //E(1, 5, 3, 7);
        //E(0, 2, 6, 4);
        //return;
    //}

    int c = (l + r) / 2;
    build(l, c);
    build(c, r);

    int hn = n / 2;
    for (int i = l; i < r; ++i) {
        int id = i >= c ? i - c : i - l;
        forn (step, hn) {
            int add = i >= c ? hn - step : step + 1;
            int id2 = (id + add) % hn;
            int to = i >= c ? l + id2 : c + id2;
            a[i].push_back(to);
        }
    }
}

void check(int n) {
    forn (i, n) {
        assert(sz(a[i]) == n - 1);
        set<int> s;
        for (int j: a[i]) {
            assert(j != i);
            assert(j >= 0 && j < n);
            s.insert(j);
        }
        assert(sz(s) == n - 1);
    }
    forn (i, n)
        forn (j, n - 1) {
            int to = a[i][j];
            assert(a[to][j] != i);
        }
}

int main() {
    #ifdef LOCAL
    assert(freopen("i.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n)
        a[i].clear();
    int p2 = 2;
    while (p2 < n)
        p2 *= 2;
    if (p2 == n) {
        cout << -1 << '\n';
        return 0;
    }
    build(0, n);
    check(n);
    forn (i, n) {
        for (int j: a[i])
            cout << j + 1 << ' ';
        cout << '\n';
    }
}
