#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 100005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular exp(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } // equivalent to return exp(b,MOD-2) if MOD is prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

int n,k,a[MX],sz[MX];
vi radj[MX];
bool inCyc[MX];
vi CYC;
vmi WAYS;
string cur[MX];
mi ways[MX];

void dfs(int a) {
    sz[a] ++;
    F0Rd(i,sz(radj[a])) if (inCyc[radj[a][i]]) {
        radj[a].erase(radj[a].begin()+i);
    }
    trav(t,radj[a]) {
        dfs(t);
        sz[a] += sz[t];
    }
    sort(all(radj[a]), [](int a, int b) { return sz[a] > sz[b]; });
}

mi tri(mi x, int y) {
    mi res = 1;
    F0R(i,y) {
        res *= x+i;
        res /= i+1;
    }
    // ps("HA",x,y);
    return res;
}

void dfs2(int a, string& s) {
    ways[a] = k;
    s += '(';
    vector<string> tmp;
    vmi tmp2;
    F0R(i,sz(radj[a])) {
        int t = radj[a][i];
        if (i == 0 && (sz(radj[a]) == 1 || sz[t] > sz[radj[a][i+1]])) {
            dfs2(t,s);
            ways[a] *= ways[t];
            // ps("??",t,ways[t]);
        } else {
            tmp.pb(""); dfs2(t,tmp.back());
            // ps("HUH",t,ways[t]);
            tmp2.pb(ways[t]);
        }
    }
    for (int i = 0; i < sz(tmp); ) {
        int I = i;
        while (i < sz(tmp) && tmp[i] == tmp[I]) i ++;
        mi x = tmp2[I]; int y = i-I;
        ways[a] *= tri(x,y);
    }
    trav(t,tmp) s += t;
    s += ')';
}

void init() {
    vi cyc;
    setIO(); re(n,k);
    FOR(i,1,n+1) {
        re(a[i]);
        radj[a[i]].pb(i);
    }
    int x = a[1], y = a[a[1]]; while (x != y) x = a[x], y = a[a[y]];
    for (int t = x; !inCyc[t]; t = a[t]) {
        cyc.pb(t);
        inCyc[t] = 1;
    }
    // ps(cyc);
    trav(t,cyc) dfs(t);
    map<string,int> m;
    trav(t,cyc) {
        dfs2(t,cur[t]);
        if (!m.count(cur[t])) {
            int co = sz(m);
            m[cur[t]] = co;
        }
        CYC.pb(m[cur[t]]);
        WAYS.pb(ways[t]);
    }
}

mi prod(vmi v) {
    mi res = 1;
    trav(t,v) res *= t;
    return res;
}

bool reflect(vi v) {
    auto V = v; reverse(all(V)); return v == V;
}

mi oops(vmi WAYS, int a) {
    vi res(sz(WAYS));
    mi ans = 1;
    F0R(i,sz(WAYS)) {
        res[i] = (a-i+sz(WAYS))%sz(WAYS);
        if (res[i] <= i) {
            ans *= WAYS[i];
            // ps("HUH",i,WAYS,WAYS[i]);
        }
    }
    return ans;
}
int main() {
    init();
    // ps(CYC,WAYS);
    int smallest = 0;
    FOR(x,1,sz(CYC)+1) if (sz(CYC)%x == 0) if (vi(CYC.begin()+x,CYC.end()) == vi(CYC.begin(),CYC.end()-x)) {
        smallest = x;
        break;
    }
    // ps(CYC,WAYS); exit(0);
    mi sum = 0;
    map<int,int> g;
    for (int i = 0; i < sz(CYC); i += smallest) g[__gcd(i,sz(CYC))] ++;
    trav(t,g) sum += t.s*prod(vmi(WAYS.begin(),WAYS.begin()+t.f)); 
    //ps("WHAT",CYC);
    int cnt = 0;
    while (!reflect(vi(CYC.begin()+1,CYC.begin()+smallest)) && cnt < sz(CYC)) {
        rotate(CYC.begin(),CYC.begin()+1,CYC.end());
        rotate(WAYS.begin(),WAYS.begin()+1,WAYS.end());
        cnt ++;
    }
    if (reflect(vi(CYC.begin()+1,CYC.begin()+smallest))) {
        //ps("A",sum);
        if (sz(CYC)/smallest % 2 == 0) {
            sum += sz(CYC)/smallest/2*oops(WAYS,0);
            sum += sz(CYC)/smallest/2*oops(WAYS,smallest);
        } else {
            sum += sz(CYC)/smallest*oops(WAYS,0);
            //ps("HUH",WAYS);
        }
        sum /= 2*sz(CYC)/smallest;
    } else {
        sum /= sz(CYC)/smallest;
    }
    ps(sum);
}


/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/