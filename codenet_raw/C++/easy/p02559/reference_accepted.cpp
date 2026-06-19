#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int SEG_LEN = 1 << 20;
vector<ll> seg(SEG_LEN * 2);

void add(int pos, ll val) {
    pos += SEG_LEN;
    seg[pos] += val;
    while (true) {
        pos /= 2;
        if (pos == 0) break;
        seg[pos] += val;
    }
}

ll sum(int l, int r) {
    l += SEG_LEN;
    r += SEG_LEN;
    ll res = 0;
    while (l < r) {
        if (l % 2) res += seg[l++];
        if (r % 2) res += seg[--r];
        l /= 2;
        r /= 2;
    }
    return res;
}

int main() {
    int N, Q;  cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        ll a;  cin >> a;
        add(i, a);
    }

    for (int _ = 0; _ < Q; ++_) {
        int q;  cin >> q;
        if (q == 0) {
            // add query
            int pos;  ll val;  cin >> pos >> val;
            add(pos, val);
        }
        if (q ==  1) {
            // get sum query
            int l, r;  cin >> l >> r;
            cout << sum(l, r) << endl;
        }
    }
}
