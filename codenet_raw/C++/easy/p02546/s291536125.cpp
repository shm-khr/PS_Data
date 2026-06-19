#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (s[n - 1] == 's') {
        s += "es";
    } else {
        s += s;
    }
    cout << s;
}