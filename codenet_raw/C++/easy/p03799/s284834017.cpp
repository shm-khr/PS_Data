#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define mod 1000000007
#define All(v) v.begin(),v.end()

using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;

    ll ans = 0;

    if(m >= n*2)
    {
        ans += n;
        m -= n*2;
    }

    ans += m/4;

    cout << ans << endl;



    return 0;
}
