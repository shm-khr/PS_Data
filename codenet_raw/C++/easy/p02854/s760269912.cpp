#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    vector<long long> a(n, 0);
    long long total = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a.at(i);
        total += a.at(i);
    }

    bool even = false;
    long long half = 0;
    if(total % 2 == 0) {
        half = total / 2;
        even = true;
    }else {
        half = total / 2;
    }


    long long halflen = 0;
    bool sw = false;
    long long truehalf = 0;

    for(int i = 0; i < n; ++i) {
        halflen += a.at(i);
        if(halflen >= half) {
            truehalf = halflen;
            break;
        }
    }

    cout << truehalf*2 - total << endl;
}