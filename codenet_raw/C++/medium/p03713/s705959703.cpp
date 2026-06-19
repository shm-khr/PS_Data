#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef long double ld;
#define txt                        \
    freopen("ip.txt", "r", stdin); \
    freopen("op.txt", "w", stdout)
#define a3 INT_MAX
#define i3 INT_MIN
#define a6 INT64_MAX
#define i6 INT64_MIN
#define F first
#define S second
#define pb push_back
#define sz(v) (int)v.size()
#define fo(i, n) for (int i = 0; i < (int)n; i++)
#define rep(i, k, n) for (int i = k < (int)n ? k : k - 1; k < (int)n ? i < (int)n : i >= (int)n; k < (int)n ? i += 1 : i -= 1)
#define quickie                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define deb(x) cout << (#x) << " " << (x) << "\n";
#define newl cout << "\n"
#define all(s) s.begin(), s.end()
#define pi 3.14159265358979323846
#define fp(x) fixed << setprecision(x) <<
vector<int> arr;
vector<ll> ar;
template <class T>
bool div2(T a)
{
    return !(a & 1);
}
template <class T>
T mod(T a)
{
    if (a < 0)
    {
        a += 1000000007;
    }
    return a % 1000000007;
}
template <class T>
T addmod(T a, T b)
{
    return (mod(a) + mod(b)) % 1000000007;
}
template <class T>
T prodmod(T a, T b)
{
    return (mod(a) * mod(b)) % 1000000007;
}
template <class T>
T bin_exp(T a, T b)
{
    T res = 1;
    T temp = 1;
    if (b <= 1)
        return a;
    if (b % 2 == 0)
        res = bin_exp(a * a, b / 2);
    else
    {
        res *= a;
        temp = bin_exp(a, --b);
    }
    return res * temp;
}
template <class T>
T bin_expmod(T a, T b)
{
    T res = 1;
    T temp = 1;
    if (b <= 1)
        return a;
    if (b % 2 == 0)
        res = bin_expmod(prodmod(a, a), b / 2);
    else
    {
        res = prodmod(a, res);
        temp = bin_exp(a, --b);
    }
    return prodmod(res, temp);
}

template <class T>
int digits(T a)
{
    vector<long long> dig = {
        0,
        9,
        99,
        999,
        9999,
        99999,
        999999,
        9999999,
        99999999,
        999999999,
        9999999999,
        99999999999,
        999999999999,
        9999999999999,
        99999999999999,
        999999999999999,
        9999999999999999,
        99999999999999999,
        999999999999999999,
        INT64_MAX};
    auto it = lower_bound(dig.begin(), dig.end(), a);
    int idx = (it - dig.begin());
    return idx;
}
template <class T>
int sumAllInts(T n)
{
    int a = 1;
    int su = 0;
    while (n)
    {
        su += n % 10;
        n /= 10;
    }
    return su;
}
template <class T>
void split(char c, T s)
{
    int n = s.size();
    int i = 0;
    while ((cout << s[i], i += 1) && (i < n) && (cout << c << ' '))
        ;
}
template <class T>
ll fib(T a)
{
    return ((a * (a + 1)) / 2);
}

template <class T>
ll nC2(T a)
{
    return ((a * (a - 1)) / 2);
}

//fxns : div2, mod, addmod, prodmod, bin_expmod, bin_exp
// digits, sumAllInts, split, fib, nC2,
ll calc(ll wid,ll high){
    ll w1 = wid/2;
    ll w2 = (wid + 1)/2;
    ll diff = a3;
    for (ll i = 1; i < high; i++)
    {
        ll t1 = i*wid;
        ll t2 = w1*(high - i);
        ll t3 = w2*(high - i);
        ll mi = min(t1,min(t2,t3));
        ll ma = max(t1,max(t2,t3));
        diff = min(diff,ma - mi);   
    }
    return diff;
}


void solve()
{
    ll h, w;
    cin >> h >> w;
    
     if (h % 3 == 0 || w % 3 == 0)
    {
        cout << 0;
        return;
    }
    else
    {
        ll ans1 = calc(w,h);
        ll ans2 = calc(h,w);
        cout<<min(ans1,ans2);
    }
    
}
int main()
{
    quickie;
    //txt;
    //freopen("ip.txt", "r", stdin);
    solve();
    //cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s."<<endl;
    return 0;
}