#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    if (n == 2) {
        cout << -1 << endl;
    }
    if (n & 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                if (j) cout << " ";
                cout << (i+j+1) % n + 1;
            }
            cout << endl;
        }
    } else {
        int t = n/2;
        for (int i = 0; i < n; i++) {
            if (i < t) cout << (i+1) % n + 1 << " " << (i+t) % n + 1;
            else cout << (i+t) % n + 1 << " " << (i+1) % n + 1;
            for (int j = 1; j < n-1; j++) {
                if (j == t-1) continue;
                cout << " ";
                cout << (i+j+1) % n + 1;
            }
            cout << endl;
        }
    }
    return 0;
}