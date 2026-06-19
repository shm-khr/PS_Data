#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    _LL n, k; cin >> n >> k;
    _LL ans = 0;
    _LL knum = n / k;
    ans += knum * knum * knum;
    if( k % 2 == 0 )
    {
        _LL k2num = (n + (k / 2)) / k;
        ans += k2num * k2num * k2num;
    }
    cout << ans << endl;
}