#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int INF = 1e9+10;
int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        ll a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(a == b || b == a+1)
        {
            cout << 2 * (a-1) << endl;
            continue;
        }
        ll c = a * b;
        ll n = sqrt(c);
        if(n * n == c)
        {
            cout << 2 * n - 3 << endl;
            continue;
        }
        if(n * (n+1) < c)
        {
            cout << 2 * n - 1 << endl;
        }
        else
        {
            cout << 2 * n - 2 << endl;
        }
    }
}
