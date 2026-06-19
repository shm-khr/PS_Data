
//#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>
using namespace std;
//@起動時
struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} __initon;
//衝突対策
#define ws ___ws
struct T {
    int f, s, t;
    T() { f = -1, s = -1, t = -1; }
    T(int f, int s, int t) : f(f), s(s), t(t) {}
    bool operator<(const T &r) const {
        return f != r.f ? f < r.f : s != r.s ? s < r.s : t < r.t;
        //return f != r.f ? f > r.f : s != r.s ? s > r.s : t > r.t; 大きい順
    }
    bool operator>(const T &r) const {
        return f != r.f ? f > r.f : s != r.s ? s > r.s : t > r.t;
        //return f != r.f ? f > r.f : s != r.s ? s > r.s : t > r.t; 小さい順
    }
    bool operator==(const T &r) const {
        return f == r.f && s == r.s && t == r.t;
    }
    bool operator!=(const T &r) const {
        return f != r.f || s != r.s || t != r.t;
    }
    int operator[](int i) {
        assert(i < 3);
        return i == 0 ? f : i == 1 ? s : t;
    }
};
#define int long long
#define ll long long
#define double long double
#define ull unsigned long long
using dou = double;
using itn = int;
using str = string;
using bo= bool;
#define au auto
using P = pair<ll, ll>;

#define fi first
#define se second
#define vec vector
#define beg begin
#define rbeg rbegin
#define con continue
#define bre break
#define brk break
#define is ==


//マクロ省略系 コンテナ

using vi = vector<int>;
#define _overloadvvi(_1, _2, _3, _4, name, ...) name
#define vvi0() vec<vi>
#define vvi1(a) vec<vi> a
#define vvi2(a, b) vec<vi> a(b)
#define vvi3(a, b, c) vec<vi> a(b,vi(c))
#define vvi4(a, b, c, d) vec<vi> a(b,vi(c,d))
#define vvi(...) _overloadvvi(__VA_ARGS__,vvi4,vvi3,vvi2 ,vvi1,vvi0)(__VA_ARGS__)


using vl = vector<ll>;
#define _overloadvvl(_1, _2, _3, _4, name, ...) name
#define vvl1(a) vec<vl> a
#define vvl2(a, b) vec<vl> a(b)
#define vvl3(a, b, c) vec<vl> a(b,vl(c))
#define vvl4(a, b, c, d) vec<vl> a(b,vl(c,d))
#define vvl(...) _overloadvvl(__VA_ARGS__,vvl4,vvl3,vvl2 ,vvl1)(__VA_ARGS__)

using vb = vector<bool>;
#define _overloadvvb(_1, _2, _3, _4, name, ...) name
#define vvb1(a) vec<vb> a
#define vvb2(a, b) vec<vb> a(b)
#define vvb3(a, b, c) vec<vb> a(b,vb(c))
#define vvb4(a, b, c, d) vec<vb> a(b,vb(c,d))
#define vvb(...) _overloadvvb(__VA_ARGS__,vvb4,vvb3,vvb2 ,vvb1)(__VA_ARGS__)

using vs = vector<string>;
#define _overloadvvs(_1, _2, _3, _4, name, ...) name
#define vvs1(a) vec<vs> a
#define vvs2(a, b) vec<vs> a(b)
#define vvs3(a, b, c) vec<vs> a(b,vs(c))
#define vvs4(a, b, c, d) vec<vs> a(b,vs(c,d))
#define vvs(...) _overloadvvs(__VA_ARGS__,vvs4,vvs3,vvs2 ,vvs1)(__VA_ARGS__)

using vd = vector<double>;
#define _overloadvvd(_1, _2, _3, _4, name, ...) name
#define vvd1(a) vec<vd> a
#define vvd2(a, b) vec<vd> a(b)
#define vvd3(a, b, c) vec<vd> a(b,vd(c))
#define vvd4(a, b, c, d) vec<vd> a(b,vd(c,d))
#define vvd(...) _overloadvvd(__VA_ARGS__,vvd4,vvd3,vvd2 ,vvd1)(__VA_ARGS__)

using vc=vector<char>;
#define _overloadvvc(_1, _2, _3, _4, name, ...) name
#define vvc1(a) vec<vc> a
#define vvc2(a, b) vec<vc> a(b)
#define vvc3(a, b, c) vec<vc> a(b,vc(c))
#define vvc4(a, b, c, d) vec<vc> a(b,vc(c,d))
#define vvc(...) _overloadvvc(__VA_ARGS__,vvc4,vvc3,vvc2 ,vvc1)(__VA_ARGS__)

using vp = vector<P>;
#define _overloadvvp(_1, _2, _3, _4, name, ...) name
#define vvp1(a) vec<vp> a
#define vvp2(a, b) vec<vp> a(b)
#define vvp3(a, b, c) vec<vp> a(b,vp(c))
#define vvp4(a, b, c, d) vec<vp> a(b,vp(c,d))

using vt = vector<T>;
#define _overloadvvt(_1, _2, _3, _4, name, ...) name
#define vvt1(a) vec<vt> a
#define vvt2(a, b) vec<vt> a(b)
#define vvt3(a, b, c) vec<vt> a(b,vt(c))
#define vvt4(a, b, c, d) vec<vt> a(b,vt(c,d))

#define v3i(a, b, c, d) vector<vector<vi>> a(b, vector<vi>(c, vi(d)))
#define v3d(a, b, c, d) vector<vector<vd>> a(b, vector<vd>(c, vd(d)))
#define v3m(a, b, c, d) vector<vector<vm>> a(b, vector<vm>(c, vm(d)))

#define _vvi vector<vi>
#define _vvl vector<vl>
#define _vvb vector<vb>
#define _vvs vector<vs>
#define _vvd vector<vd>
#define _vvc vector<vc>
#define _vvp vector<vp>

#define PQ priority_queue<ll, vector<ll>, greater<ll> >
#define tos to_string
using mapi = map<int, int>;
using mapd = map<dou, int>;
using mapc = map<char, int>;
using maps = map<str, int>;
using seti = set<int>;
using setd = set<dou>;
using setc = set<char>;
using sets = set<str>;
using qui = queue<int>;
#define bset bitset
#define uset unordered_set
#define mset multiset
#define umap unordered_map
#define umapi unordered_map<int,int>
#define umapp unordered_map<P,int>
#define mmap multimap

//マクロ 繰り返し
#define _overloadrep(_1, _2, _3, _4, name, ...) name
# define _rep(i, n) for(int i = 0,_lim=n; i < _lim ; i++)
#define repi(i, m, n) for(int i = m,_lim=n; i < _lim ; i++)
#define repadd(i, m, n, ad) for(int i = m,_lim=n; i < _lim ; i+= ad)
#define rep(...) _overloadrep(__VA_ARGS__,repadd,repi,_rep,)(__VA_ARGS__)
#define _rer(i, n) for(int i = n; i >= 0 ; i--)
#define reri(i, m, n) for(int i = m,_lim=n; i >= _lim ; i--)
#define rerdec(i, m, n, dec) for(int i = m,_lim=n; i >= _lim ; i-=dec)
#define rer(...) _overloadrep(__VA_ARGS__,rerdec,reri,_rer,)(__VA_ARGS__)
#define fora(a, b) for(auto&& a : b)
#define forg(gi, ve) for (int gi = 0, f, t, c; gi < ve.size() && (f = ve[gi].f, t = ve[gi].t, c = ve[gi].c, true); gi++)
#define fort(gi, ve) for (int gi = 0, f, t, c; gi < ve.size() && (f = ve[gi].f, t = ve[gi].t, c = ve[gi].c, true); gi++)if(t!=p)
//#define fort(gi, ve) for (int gi = 0, f, t, c;gi<ve.size()&& (gi+= (ve[gi].t==p))< ve.size() && (f = ve[gi].f,t=ve[gi].t, c = ve[gi].c,true); gi++)

//マクロ 定数
#define k3 1010
#define k4 10101
#define k5 101010
#define k6 1010101
#define k7 10101010
const int inf = (int) 1e9 + 100;
const ll linf = (ll) 1e18 + 100;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795029L;
ll ma = numeric_limits<ll>::min();
ll mi = numeric_limits<ll>::max();
const int y4[] = {-1, 1, 0, 0};
const int x4[] = {0, 0, -1, 1};
const int y8[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int x8[] = {1, 0, -1, 0, 1, -1, 1, -1};

//マクロ省略形 関数等
#define arsz(a) (sizeof(a)/sizeof(a[0]))
#define sz(a) ((int)(a).size())
#define rs resize
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()


inline void sort(string &a) { sort(a.begin(), a.end()); }
template<class T> inline void sort(vector<T> &a) { sort(a.begin(), a.end()); };
template<class T> inline void sort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len); };
template<class T, class F> inline void sort(vector<T> &a, F f) { sort(a.begin(), a.end(), [&](T l, T r) { return f(l) < f(r); }); };
enum ___pcomparator {
    fisi, fisd, fdsi, fdsd, sifi, sifd, sdfi, sdfd
};
inline void sort(vector<P> &a, ___pcomparator type) {
    switch (type) {
        case fisi:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi < r.fi : l.se < r.se; });
            break;
        case fisd:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi < r.fi : l.se > r.se; });
            break;
        case fdsi:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi > r.fi : l.se < r.se; });
            break;
        case fdsd:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi > r.fi : l.se > r.se; });
            break;
        case sifi:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se < r.se : l.fi < r.fi; });
            break;
        case sifd:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se < r.se : l.fi > r.fi; });
            break;
        case sdfi:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se > r.se : l.fi < r.fi; });
            break;
        case sdfd:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se > r.se : l.fi > r.fi; });
            break;
    }
};
inline void sort(vector<T> &a, ___pcomparator type) {
    switch (type) {
        case fisi:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f < r.f : l.s < r.s; });
            break;
        case
            fisd:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f < r.f : l.s > r.s; });
            break;
        case
            fdsi:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f > r.f : l.s < r.s; });
            break;
        case
            fdsd:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f > r.f : l.s > r.s; });
            break;
        case
            sifi:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s < r.s : l.f < r.f; });
            break;
        case
            sifd:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s < r.s : l.f > r.f; });
            break;
        case
            sdfi:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s > r.s : l.f < r.f; });
            break;
        case
            sdfd:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s > r.s : l.f > r.f; });
            break;
    }
};
template<class T> inline void rsort(vector<T> &a) { sort(a.begin(), a.end(), greater<T>()); };
template<class T> inline void rsort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len, greater<T>()); };
template<class U, class F> inline void rsort(vector<U> &a, F f) { sort(a.begin(), a.end(), [&](U l, U r) { return f(l) > f(r); }); };
template<class U> inline void sortp(vector<U> &a, vector<U> &b) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    sort(c);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;;
    }
};
//F = T<T>
//例えばreturn p.fi + p.se;
template<class U, class F> inline void sortp(vector<U> &a, vector<U> &b, F f) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    sort(c, f);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U, class F> inline void sortp(vector<U> &a, vector<U> &b, char type) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    sort(c, type);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U> inline void rsortp(vector<U> &a, vector<U> &b) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    rsort(c);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U, class F> inline void rsortp(vector<U> &a, vector<U> &b, F f) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    rsort(c, f);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U> inline void sortt(vector<U> &a, vector<U> &b, vector<U> &c) {
    vt r;
    int n = sz(a);
    assert(n == sz(b));
    assert(n == sz(c));
    rep(i, n)r.eb(a[i], b[i], c[i]);
    sort(r);
    rep(i, n) {
        a[i] = r[i].f;
        b[i] = r[i].s;
        c[i] = r[i].t;
    }
};
template<class U, class F> inline void sortt(vector<U> &a, vector<U> &b, vector<U> &c, F f) {
    vt r;
    int n = sz(a);
    assert(n == sz(b));
    assert(n == sz(c));
    rep(i, n)r.eb(a[i], b[i], c[i]);
    sort(r, f);
    rep(i, n) {
        a[i] = r[i].f;
        b[i] = r[i].s;
        c[i] = r[i].t;
    }
};
template<class U, class F> inline void rsortt(vector<U> &a, vector<U> &b, vector<U> &c, F f) {
    vt r;
    int n = sz(a);
    assert(n == sz(b));
    assert(n == sz(c));
    rep(i, n)r.eb(a[i], b[i], c[i]);
    rsort(r, f);
    rep(i, n) {
        a[i] = r[i].f;
        b[i] = r[i].s;
        c[i] = r[i].t;
    }
};
template<class T> inline void sort2(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)sort(a[i]); }
template<class T> inline void rsort2(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)rsort(a[i]); }
template<typename A, size_t N, typename T> void fill(A (&a)[N], const T &v) { rep(i, N)a[i] = v; }
template<typename A, size_t N, size_t O, typename T> void fill(A (&a)[N][O], const T &v) { rep(i, N)rep(j, O)a[i][j] = v; }
template<typename A, size_t N, size_t O, size_t P, typename T> void fill(A (&a)[N][O][P], const T &v) { rep(i, N)rep(j, O)rep(k, P)a[i][j][k] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, typename T> void fill(A (&a)[N][O][P][Q], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)a[i][j][k][l] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, typename T> void fill(A (&a)[N][O][P][Q][R], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)a[i][j][k][l][m] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, size_t S, typename T> void fill(A (&a)[N][O][P][Q][R][S], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)rep(n, S)a[i][j][k][l][m][n] = v; }

template<typename V, typename T>
void fill(V &xx, const T vall) {
    xx = vall;
}
template<typename V, typename T>
void fill(vector<V> &vecc, const T vall) {
    for (auto &&vx: vecc) fill(vx, vall);
}

//@汎用便利関数 入力
template<typename T = int> T _in() {
    T x;
    cin >> x;
    return (x);
}
#define _overloadin(_1, _2, _3, _4, name, ...) name
#define in0() _in()
#define in1(a) cin>>a
#define in2(a, b) cin>>a>>b
#define in3(a, b, c) cin>>a>>b>>c
#define in4(a, b, c, d) cin>>a>>b>>c>>d
#define in(...) _overloadin(__VA_ARGS__,in4,in3,in2 ,in1,in0)(__VA_ARGS__)

#define _overloaddin(_1, _2, _3, _4, name, ...) name
#define din1(a) int a;cin>>a
#define din2(a, b) int a,b;cin>>a>>b
#define din3(a, b, c) int a,b,c;cin>>a>>b>>c
#define din4(a, b, c, d) int a,b,c,d;cin>>a>>b>>c>>d
#define din(...) _overloadin(__VA_ARGS__,din4,din3,din2 ,din1)(__VA_ARGS__)

#define _overloaddind(_1, _2, _3, _4, name, ...) name
#define din1d(a) int a;cin>>a;a--
#define din2d(a, b) int a,b;cin>>a>>b;a--,b--
#define din3d(a, b, c) int a,b,c;cin>>a>>b>>c;a--,b--,c--
#define din4d(a, b, c, d) int a,b,c,d;cin>>a>>b>>c>>d;;a--,b--,c--,d--
#define dind(...) _overloaddind(__VA_ARGS__,din4d,din3d,din2d ,din1d)(__VA_ARGS__)


string sin() { return _in<string>(); }
ll lin() { return _in<ll>(); }
#define na(a, n) a.resize(n); rep(i,n) cin >> a[i];
#define nao(a, n) a.resize(n+1); rep(i,n) cin >> a[i+1];
#define nad(a, n) a.resize(n); rep(i,n){ cin >> a[i]; a[i]--;}
#define na2(a, b, n) a.resize(n),b.resize(n);rep(i, n)cin >> a[i] >> b[i];
#define na2d(a, b, n) a.resize(n),b.resize(n);rep(i, n){cin >> a[i] >> b[i];a[i]--,b[i]--;}
#define na3(a, b, c, n) a.resize(n),b.resize(n),c.resize(n);   rep(i, n)cin >> a[i] >> b[i] >> c[i];
#define na3d(a, b, c, n) a.resize(n),b.resize(n),c.resize(n);   rep(i, n){cin >> a[i] >> b[i] >> c[i];a[i]--,b[i]--,c[i]--;}
#define nt(a, h, w) resize(a,h,w);rep(hi,h)rep(wi,w) cin >> a[hi][wi];
#define ntd(a, h, w) rs(a,h,w);rep(hi,h)rep(wi,w) cin >> a[hi][wi], a[hi][wi]--;
#define ntp(a, h, w) fill(a,'#');rep(hi,1,h+1)rep(wi,1,w+1) cin >> a[hi][wi];

//デバッグ
#define sp << " " <<

#define debugName(VariableName) # VariableName

#define _deb1(x) cerr <<  debugName(x)<<" = "<<x << endl
#define _deb2(x, y) cerr <<  debugName(x)<<" = "<<x<<", "<< debugName(y)<<" = "<<y<< endl
#define _deb3(x, y, z) cerr <<  debugName(x)<<" = "<<x  << ", " <<  debugName(y)<<" = "<<y <<", " debugName(z)<<" = "<<z <<endl
#define _deb4(x, y, z, a) cerr <<  debugName(x)<<" = "<<x <<", " <<   debugName(y)<<" = "<<y <<", " <<  debugName(z)<<" = "<<z <<", " <<  debugName(a)<<" = "<<a<<endl
#define _deb5(x, y, z, a, b) cerr <<  debugName(x)<<" = "<<x <<", " <<   debugName(y)<<" = "<<y <<", " <<  debugName(z)<<" = "<<z <<", " <<  debugName(a)<<" = "<<a<<", " <<  debugName(b)<<" = "<<b<<endl


#define _overloadebug(_1, _2, _3, _4, _5, name, ...) name
#define debug(...) _overloadebug(__VA_ARGS__,_deb5,_deb4,_deb3,_deb2,_deb1)(__VA_ARGS__)
#define deb(...) _overloadebug(__VA_ARGS__,_deb5,_deb4,_deb3,_deb2,_deb1)(__VA_ARGS__)
#define debugline(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n'
void ole() {
#ifdef _DEBUG
    debugline("ole");
    exit(0);
#endif
    string a = "a";
    rep(i, 30)a += a;
    rep(i, 1 << 17)cout << a << endl;
    cout << "OLE 出力長制限超過" << endl;
    exit(0);
}
void tle() { while (inf)cout << inf << endl; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll gcd(vi b) {
    ll res = b[0];
    for (auto &&v :b)res = gcd(v, res);
    return res;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll rev(ll a) {
    ll res = 0;
    while (a) {
        res *= 10;
        res += a % 10;
        a /= 10;
    }
    return res;
}
template<class T> void rev(vector<T> &a) {
    reverse(all(a));
}
void rev(string &a) {
    reverse(all(a));
}
ll ceil(ll a, ll b) {
    if (b == 0) {
        debugline("ceil");
        deb(a, b);
        ole();
        return -1;
    } else return (a + b - 1) / b;
}
ll sqrt(ll a) {
    if (a < 0) {
        debugline("sqrt");
        deb(a);
        ole();
    }
    ll res = (ll) std::sqrt(a);
    while (res * res < a)res++;
    return res;
}
double log(double e, double x) { return log(x) / log(e); }
ll sig(ll t) { return (1 + t) * t / 2; }
ll sig(ll s, ll t) { return (s + t) * (t - s + 1) / 2; }

vi divisors(int v) {
    vi res;
    double lim = std::sqrt(v);
    for (int i = 1; i <= lim; ++i) {
        if (v % i == 0) {
            res.pb(i);
            if (i != v / i)res.pb(v / i);
        }
    }
    return res;
}

vb isPrime;
vi primes;

void setPrime() {
    int len = 4010101;
    isPrime.resize(4010101);
    fill(isPrime, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= sqrt(len) + 5; ++i) {
        if (!isPrime[i])continue;
        for (int j = 2; i * j < len; ++j) {
            isPrime[i * j] = false;
        }
    }
    rep(i, len)if (isPrime[i])primes.pb(i);
}

vi factorization(int v) {
    int tv = v;
    vi res;
    if (isPrime.size() == 0)setPrime();
    for (auto &&p :primes) {
        if (v % p == 0)res.push_back(p);
        while (v % p == 0) {
            v /= p;
        }
        if (v == 1 || p * p > tv)break;
    }
    if (v > 1)res.pb(v);
    return res;
}
inline bool inside(int h, int w, int H, int W) { return h >= 0 && w >= 0 && h < H && w < W; }
inline bool inside(int v, int l, int r) { return l <= v && v < r; }
#define ins inside
ll u(ll a) { return a < 0 ? 0 : a; }
template<class T> vector<T> u(const vector<T> &a) {
    vector<T> ret = a;
    fora(v, ret)v = u(v);
    return ret;
}
#define MIN(a) numeric_limits<a>::min()
#define MAX(a) numeric_limits<a>::max()


int n, m, k, d, H, W, x, y, z, q;
int cou;
vi a, b, c;
vvi (s, 0, 0);
vvc (ba, 0, 0);
vp p;
template<class M> struct Monoid {
    int i;
    M v;
    Monoid(ll i, M v) : i(i), v(v) {}
};
#define segMinl(M) [](int i, int v) {return Monoid<M>(i,v);}, [](Monoid<M> a, Monoid<M> b){return a.v <= b.v ? a : b;}, [](int len, int x){return x;}, Monoid<M>(-1, MAX(M))
#define segMinr(M) [](int i, int v) {return Monoid<M>(i,v);}, [](Monoid<M> a, Monoid<M> b){return a.v <  b.v ? a : b;}, [](int len, int x){return x;}, Monoid<M>(-1, MAX(M))
#define segMaxl(M) [](int i, int v) {return Monoid<M>(i,v);}, [](Monoid<M> a, Monoid<M> b){return a.v >= b.v ? a : b;}, [](int len, int x){return x;}, Monoid<M>(-1, MIN(M))
#define segMaxr(M) [](int i, int v) {return Monoid<M>(i,v);}, [](Monoid<M> a, Monoid<M> b){return a.v >  b.v ? a : b;}, [](int len, int x){return x;}, Monoid<M>(-1, MIN(M))
//                      個数　最小値候補
#define segCouMin(M) [](int cou, int v) {return Monoid<M>(1,v);}, [](Monoid<M> a, Monoid<M> b){int coum = 0; if(a.v<=b.v)coum+=a.i; if(a.v>=b.v)coum+=b.i;return Monoid<M>(coum,min(a.v,b.v));}, [](int len, int x){return x;}, Monoid<M>(0, MAX(M))
#define segCouMax(M) [](int cou, int v) {return Monoid<M>(1,v);}, [](Monoid<M> a, Monoid<M> b){int coum = 0; if(a.v>=b.v)coum+=a.i; if(a.v<=b.v)coum+=b.i;return Monoid<M>(coum,max(a.v,b.v));}, [](int len, int x){return x;}, Monoid<M>(0, MIN(M))
#define segSum(M)  [](int i, int v) {return Monoid<M>(i,v);}, [](Monoid<M> a, Monoid<M> b){return Monoid<M>(a.i+b.i,a.v+b.v);} , [](int len, int x){return len * x;}, Monoid<M>(0,0)

//一つずつ初期化するのは大変
//vi を渡してセットするのがベスト
//updateは諦める
template<class M> struct SegmentLazyAdd {
    using fini= function<Monoid<M>(int, M)>;
    using func=function<Monoid<M>(Monoid<M>, Monoid<M>)>;
    using feval = function<ll(int, int)>;
    int n;
    vector<Monoid<M>> seg;
    vi lazy;//全体に足された数を持つ 3333なら3
    fini toMonoid; //Monoidを初期化する
    const func f;        //Monoid同士の演算結果を返す
    const feval getAdd;  //len,xを受け取り、segに加える数を返す
    const Monoid<M> e;
    vi arch;//遅延評価を行うやつ
    void init(vi &a) {
        n = 1;
        int asz = a.size();
        while (n < asz)n *= 2;
        seg.resize(2 * n - 1, e);
        lazy.resize(2 * n - 1, 0);
        rep(i, asz) seg[i + n - 1] = toMonoid(i, a[i]);
        rer(i, n - 2)seg[i] = f(seg[i * 2 + 1], seg[i * 2 + 2]);
    }
    SegmentLazyAdd(vi &a, fini toMonoid, func f, feval fe, Monoid<M> e) : f(f), toMonoid(toMonoid), getAdd(fe), e(e) { init(a); }
    SegmentLazyAdd(int len, fini toMonoid, func f, feval fe, Monoid<M> e) : f(f), toMonoid(toMonoid), getAdd(fe), e(e) {
        vi a(len);
        init(a);
    }
    SegmentLazyAdd(vi &a, func f, feval fe, Monoid<M> e) : f(f), toMonoid(toMonoid), getAdd(fe), e(e) { toMonoid = [](int i, int v) { return Monoid<M>(i, v); }, init(a); }
    SegmentLazyAdd(int len, func f, feval fe, Monoid<M> e) : f(f), toMonoid(toMonoid), getAdd(fe), e(e) {
        toMonoid = [](int i, int v) { return Monoid<M>(i, v); };
        vi a(len);
        init(a);
    }
    void eval() {
        rer(j, sz(arch) - 1) {
            int i = arch[j];
            //iは1index
            //lazyは0index
            int v = lazy[i - 1];
            if (!v)continue;
            lazy[i * 2 - 1] += v;
            lazy[i * 2] += v;
            seg[i * 2 - 1].v += v;
            seg[i * 2].v += v;
            lazy[i - 1] = 0;
        }
    }
    void gindex(int l, int r) {
        arch.clear();
        l += n;
        r += n;
        int lm = (l / (l & -l)) >> 1;
        int rm = (r / (r & -r)) >> 1;
        while (l < r) {
            if (r <= rm)arch.pb(r);
            if (l <= lm)arch.pb(l);
            l >>= 1;
            r >>= 1;
        }
        while (l) {
            arch.pb(l);
            l >>= 1;
        }
    }
    void add(int l, int r, int x) {
        int L = l + n;
        int R = r + n;
        while (L < R) {
            if (R & 1) {
                R--;
                lazy[R - 1] += x;
                seg[R - 1].v += x;
            }
            if (L & 1) {
                lazy[L - 1] += x;
                seg[L - 1].v += x;
                L++;
            }
            L >>= 1;
            R >>= 1;
        }
        gindex(l, r);
        fora(i, arch) {
            seg[i - 1] = f(seg[i * 2 - 1], seg[i * 2]);
            seg[i - 1].v += lazy[i - 1];
        }
    }
    vector<Monoid<M>> rvs;
    Monoid<M> get(int l, int r) {
        rvs.clear();
        gindex(l, r);
        eval();
        int L = l + n;
        int R = r + n;
        Monoid<M> ret = e;
        while (L < R) {
            if (L & 1) {
                ret = f(ret, seg[L - 1]);
                L++;
            }
            if (R & 1) {
                R--;
                rvs.pb(seg[R - 1]);
            }
            L >>= 1;
            R >>= 1;
        }
        rer(i, sz(rvs) - 1) {
            ret = f(ret, rvs[i]);
        }
        return ret;
    }

    int geti(int l, int r) {
        return get(l, r).i;
    }
    int getv(int l, int r) {
        return get(l, r).v;
    }
};
#define raq SegmentLazyAdd

signed main() {
    cin >> n >> q;
    raq seg(k5, segMinl);
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int s, t, a;
            cin >> s >> t >> a;
            seg.add(s, t + 1, a);
        } else {
            int s, t;
            cin >> s >> t;
            cout << seg.getv(s, t + 1) << endl;
        }
    }

    return 0;
}
