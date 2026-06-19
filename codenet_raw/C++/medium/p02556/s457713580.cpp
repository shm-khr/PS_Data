
// Problem : E - Dist Max
// Contest : AtCoder - AtCoder Beginner Contest 178
// URL : https://atcoder.jp/contests/abc178/tasks/abc178_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("Ofast")//Comment optimisations for interactive problems (use endl)
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
using ll =  int64_t;
using ld =  long double;
#define int  int64_t
#define mem(a,ss)memset( a,  ss,  sizeof(a) )/*****************************************/
#define b_s binary_search                   /*        _..._                          */
#define b_s binary_search                  /*       .'     '.      _                */
#define u_b upper_bound                   /*       /    .-""-\   _/ \              */
#define l_b lower_bound                  /*      .-|   /:.   |  | Hi/             */
#define nl cout<<endl                   /*       |  \  |:.   /.-'-./             */
#define pb push_back                   /*        | .-'-;:__.'    =/             */
#define pf push_front                 /*         .'=  *=| SDe _.='             */
#define fi first                     /*         /   _.  |    ;                */
#define se second                   /*         ;-.-'|    \   |               */
#define ppb  pop_back              /*         /   | \    _\  _\             */
#define ppf  pop_front            /*          \__/'._;.  ==' ==\           */
#define in insert                /*                   \    \   |          */
#define umap unordered_map      /*                    /   /   /          */
#define pqueue priority_que    /*                    /-._/-._/          */
#define rr return             /*                     \   `\  \         */
#define sqr(a) ((a) * (a))   /*_______________________`-._/_./________*/
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define bits(n)  __builtin_popcount(n)
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define _______1 cin >> times;for (test = 1; test <= times; test++)
#define _______0 for (test = 1; test <= times; test++)
#define ready ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int N =  200005;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const int MOD2 = 998244353;
const ld pi = atan2(0, -MOD);
const ld eps = 1e-9;
int times =  1;
int test = 1;
template<class x, class y>x max(x a, y b) {
    return (a > b) ? a : b;
}
template<class x, class y>x min(x a, y b) {
    return (a < b) ? a : b;
}
template<class x, class y>x log(x n, y r) {
    return (n > r - 1) ? 1 + log(n / r, r) : 0;
}
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
template<class T> void _R(T &x) { cin >> x; }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }

template<class T> void _W(const T &x) { cout << x ; }
template<class T, class U> void _W(const pair<T, U> &x) {_W(x.first); putchar(' '); _W(x.second);}
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); if (sizeof...(tail)) { cout << ' '; } ; W(tail...); }
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
// http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
bool isprime(int n);
bool ispalin(int num);
bool ispalinstr(string s);
bool isleapyear(int year);
int __lcm(int a, int b);
int power(int x, int y);
int digitsum(int n);
int fact(int n);
int npr(int n, int r);
int ncr(int n, int r);
int evensum(int n);
int oddsum(int n);
void sorts(string &str);
void start();
void IO_();
void solve() {
    // W("Case #", test, ":");
    W(fixed);
    // W(scientific);
    W(setprecision(0));

    _______0 IO_();
    // _______1 IO_();
} void IO_() {
///.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.
 
    
    int n;
    cin>>n;
    pair<int,int> a[n],b[n];
    for(int i=0;i<n;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	a[i].fi=x;
    	a[i].se=y;
    	b[i].fi=y;
    	b[i].se=x;
    }
    sort(a,a+n);
    sort(b,b+n);
    
    int an1=abs(a[0].fi-a[n-1].fi)+abs(a[0].se-a[n-1].se);
    int an2=abs(b[0].fi-b[n-1].fi)+abs(b[0].se-b[n-1].se);
    cout<<max(an1,an2);
    // int ans=0;
    // for(int i=0;i<n/2;i++)
    // {
    	// for(int j=n/2;j<n;j++)
    	// {
    		// ans=max(ans,abs(a[i].fi-a[j].fi)+abs(a[i].se-a[j].se));
    	// }
    // }
    // cout<<ans;
//     
    
    
    



///.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.'.
}






bool isprime(int n)
{
    if (n < 2)
        rr false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false ;
    }
    return true ;

}

bool ispalin(int num)
{
    bool flag = false;
    int digit, rev = 0, n = num;
    do
    {
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    } while (num != 0);
    if (rev == n)
        flag = true;
    return flag;
}


bool ispalinstr(string s)
{
    string ss = s;
    reverse(all(ss));
    return s == ss;
}

bool isleapyear(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    if (year % 4 == 0)
        return true;
    return false;
}

int __lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
}

int power(int x, int y)
{
    int temp;
    if ( y == 0)
        return 1;
    temp = pow(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int digitsum(int n)
{
    int c = 0;
    while (n > 0)
    {
        c++;
        n /= 10;
    }
    return c;
}

int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

int ncr(int n, int r)
{
    if (n < r)
        rr 0;
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            int m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}

int npr(int n, int r)
{
    return fact(n) / fact(n - r);
}

int evensum(int n)
{
    return (n / 2 * (n / 2 + 1));
}

int oddsum(int n)
{
    return (((n + 1) / 2) * ((n + 1) / 2));
}

void sorts(string &str)
{
    sort(str.begin(), str.end());
}

void start()
{
#ifndef ONLINE_JUDGE
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    }
#endif
}
int32_t main() {ready;  solve();}
