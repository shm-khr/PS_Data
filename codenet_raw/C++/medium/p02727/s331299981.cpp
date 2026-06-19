#include <bits/stdc++.h>
#include <functional> // for less
#include <iostream>
#define ll long long
#define ull unsigned long long
#define ld long double
#define all(ar) ar.begin(), ar.end()
#define mp make_pair
#define sot(bello) bello.begin(), bello.end()
#define bitc __builtin_popcountl
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define fill(ar, val) rep(i, sizeof(ar) / sizeof(ll)) ar[i] = val
#define fill0(ar) fill((ar), 0)
#define foreach(it, ar) for (typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++)
#define fillinf(ar, n) fr(i, 0, (n)) ar[i] = INF
#define MOD 1000000007
#define MOD1 998244353
#define print(x) {  \
             cout<<x<<endl; \
             cerr<<endl; \
             return;    \
}
#define debug(x) cerr << #x << ": " << x << endl
#define arr1d(a, n)                  \
    cout << #a << " : ";             \
    fr(_, 1, n) cout << a[_] << ' '; \
    cout << endl;
#define arr1d0(a, n)               \
    cout << #a << " : ";           \
    rep(_, n) cout << a[_] << ' '; \
    cout << endl;
#define arr2d(a, n, m)                        \
    cout << #a << " :" << endl;               \
    fr(_, 1, n)                               \
    {                                         \
        fr(__, 1, m) cout << a[_][__] << ' '; \
        cout << endl;                         \
    }
#define arr2d0(a, n, m)                     \
    cout << #a << " :" << endl;             \
    rep(_, n)                               \
    {                                       \
        rep(__, m) cout << a[_][__] << ' '; \
        cout << endl;                       \
    }
#define clr(a) memset(a, 0, sizeof(a))
#define dbug(x) cerr << #x << ": " << x << " "
auto clk = clock();
#define PI 3.1415926535897932385
#define fi first
#define se second
#define arr1d(a, n)                  \
    cout << #a << " : ";             \
    fr(_, 1, n) cout << a[_] << ' '; \
    cout << endl;
#define arr1d0(a, n)               \
    cout << #a << " : ";           \
    rep(_, n) cout << a[_] << ' '; \
    cout << endl;
#define arr2d(a, n, m)                        \
    cout << #a << " :" << endl;               \
    fr(_, 1, n)                               \
    {                                         \
        fr(__, 1, m) cout << a[_][__] << ' '; \
        cout << endl;                         \
    }
#define arr2d0(a, n, m)                     \
    cout << #a << " :" << endl;             \
    rep(_, n)                               \
    {                                       \
        rep(__, m) cout << a[_][__] << ' '; \
        cout << endl;                       \
    }

#define INF 1000000000000000000
const ld PI2 = acos(-1) / 2.0l;
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
const int dx8[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[] = {-1, 0, 1, 1, 1, 0, -1, -1};
/* This Template is authored by Ankit Anvesh */

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// gcd for negatives too
/* ll gcd(ll a, ll b) {
 if (a == 0) return b;
 if (b == 0) return a;
 if (b < 0) return gcd(a, -1 * b);
 if (a < 0) return gcd(-1 * a, b);
 if (a > b) return gcd(b, a);
 return gcd(b%a, a);
}
 */

//gcd

const ll MAXN=100010;

ll Gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    return Gcd(b, a % b);
}
//max
ll Max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
//min
ll Min(ll a, ll b)
{
    if (a < b)
        return a;
    return b;
}

void printvector(std::vector<ll> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "" << endl;
}
void printarray(ll a[], ll n)
{
    for (ll i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "" << endl;
}

ll findlcm(vector<ll> arr, ll n)
{
    // Initialize result
    ll ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
               (Gcd(arr[i], ans)));

    return ans;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll lowerbound(ll k, vector<ll> v)
{
    //lowerbound to be used when first index such that
    // ar[index]>=k is needed

    ll l = 0;
    ll size = v.size();
    ll r = size - 1;
    ll mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (v[mid] < k)
            l = mid + 1;
        else
        {
            r = mid - 1;
        }
    }
    return l;
}

ll upperbound(ll k, vector<ll> v)
{
    //lowerbound to be used when first index such that
    // ar[index]>k is needed
    ll l = 0;
    ll size = v.size();
    ll r = size - 1;
    ll mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (v[mid] > k)
            r = mid - 1;
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

ll spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

//Segment Tree Implementation

//const ll N = 100000;

ll n, m;

// BIT tree
/*
start indexing from 1
ll BIT[100010];
void update(ll x,ll val){
 
  for (; x <=n ; x +=(x&(-x)) )
     BIT[x]+=val;

}
ll query(ll x){
  ll sum=0;
  for(;x>0;x -= (x&(-x)) )
    sum+=BIT[x];
  return sum;

}*/

//Dijkstra's Algorithm
// if x->y (weight=w) then v[x].push_back(mp(y,w));

vector<ll> shortPath(vector<pair<ll, ll>> v[], ll src, ll V = 0)
{
    set<pair<ll, ll>> setds;

    ll sizee = V;
    ll IN = INF;
    vector<ll> dist(sizee, IN);
    vector<bool> vis(sizee, false);
    setds.insert(make_pair(0, src));
    dist[src] = 0;

    while (!setds.empty())
    {
        pair<ll, ll> tmp = *(setds.begin());
        setds.erase(setds.begin());

        ll u = tmp.second;
        if (vis[u])
            continue;
        vis[u] = true;
        vector<pair<ll, ll>>::iterator i;
        for (auto i = v[u].begin(); i != v[u].end(); ++i)
        {
            ll v = (*i).first;
            ll weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}










ll root(ll a[], ll r)
{
    if (a[r] == r)
    {
        return r;
    }
    else
    {
        ll x = root(a, a[r]);
        a[r] = x;
        return x;
    }
}

void unio(ll a[], ll size[], ll x, ll y)
{
    x = root(a, x);
    y = root(a, y);
    if (x == y)
    {
        return;
    }
    if (size[x] >= size[y])
    {
        a[y] = x;
        size[x] += size[y];
    }
    else
    {
        a[x] = y;
        size[y] += size[x];
    }
}

// Sieve Implementation
/* 
for (ll i=2;i<=100005;i++)
        if (p[i]==0)
        for (ll j=2*i;j<=100005;j+=i) p[j]=1; */

// Dfs search

//do not use n , m , N , C

// Using iterators in C++
//set<ll>:: iterator it;
// string to integer stuuu()
// string to long long stoll()
// string to float stof
// string.substr(position,length);
// integer to string to_string();
// intialize 2d vector vector<vector<ll>> dp(105,vector<ll>(105));
// for taking ceil use (num+den-1)/den












void neuer(ll txt)
{
   //cin>>n;
   ll x,y;
   cin>>x>>y;
   ll a,b,c;
   cin>>a>>b>>c;
   vector<ll> p(a);
   vector<ll> q(a);
   vector<ll> r(a);
   vector<pair<ll,ll>> v;
   rep(i,a){
       cin>>p[i];
       v.push_back({p[i],1});
   } 
   rep(i,b){
       cin>>q[i];
       v.push_back({q[i],2});
   } 
   rep(i,c){
       cin>>r[i];
       v.push_back({r[i],3});
   }
   sort(sot(v));
   reverse(sot(v));
   ll xc=0;
   ll yc=0;
   ll px=0;
   ll py=0;
   for(ll i=0;i<v.size();i++){
       if(xc!=x and v[i].second==3){
           xc++;
           px+=v[i].first;
        }
       if(yc!=y and v[i].second==3){
           yc++;
           py+=v[i].first;
        }
        if(xc!=x and v[i].second==1){
            xc++;
            px+=v[i].first;
        }
        if(yc!=y and v[i].second==2){
            yc++;
            py+=v[i].first;
        }

   }
   print(px+py);






   
   
   return;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x68 = 1;
    //cin >> x68;
   for (ll vi = 1; vi <= x68; vi++)
    {
        neuer(vi);
    }

    return 0;
}