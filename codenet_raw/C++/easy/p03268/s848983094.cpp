#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, ans = 0; cin >> n >> k;
    vector<int> cnt(k, 0);
    for (auto i = 1; i <= n; i++) cnt[i % k]++;
    for (auto a = 0; a < k; a++) {
        int b = (k - a) % k;
        if((2 * b) % k != 0) continue;
        ans += cnt[a] * cnt[b] * cnt[b];
    }
    cout << ans << endl;
    return 0;
}