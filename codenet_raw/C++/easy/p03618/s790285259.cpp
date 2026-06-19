#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
    return arg1.first > arg2.first;
}

int main(void) {
    string a;
    cin >> a;

    vector<int> abc(26);
    ll n = a.size();
    for(int i=0;i<n;i++) {
        abc.at(a.at(i)-'a')++;
    }

    ll ans;
    ans = n*(n-1)/2;
    for(int i=0;i<26;i++) {
        ans -= ((ll)(abc.at(i)*(abc.at(i)-1)/2));
    }
    ans++;

    cout << ans << endl;

    return 0;
}
