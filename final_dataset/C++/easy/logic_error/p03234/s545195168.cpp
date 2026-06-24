#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream& operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream& operator<<(ostream &os, vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream& operator<<(ostream &os, set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream& operator<<(ostream &os, map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int N, K;
vector<int> con;
int avi[602];

template <typename T>
struct SegTree
{
    int N;
    int head;
    vector<T> x;
    T defaultT;
    using func = function<T(const T&, const T&)>;
    func tree_update;

    T _query_search(int begin, int end, int pos, int l, int r)
    {
        if (r <= begin || l >= end) return defaultT;
        if (l >= begin && r <= end) return x[pos];
        T v_l = _query_search(begin, end, 2*pos+1, l, (l+r)/2);
        T v_r = _query_search(begin, end, 2*pos+2, (l+r)/2, r);
        return tree_update(v_l, v_r);
    }

    SegTree(int N, T val_default, func f) : N(N), defaultT(val_default), tree_update(f)
    {
        int N_tmp = 1;
        while (N_tmp < N) N_tmp <<= 1;
        x = vector<T>(N_tmp*2, defaultT);
        head = N_tmp - 1;
    }

    void update(int pos, T val)
    {
        pos += head;
        x[pos] = val;
        while (pos)
        {
            pos = (pos - 1) / 2;
            x[pos] = tree_update(x[pos*2+1], x[pos*2+2]);
        }
    }
    T query(int begin, int end)
    {
        return _query_search(begin, end, 0, 0, (int)x.size() / 2);
    }
};

template <int mod>
struct ModInt
{
    using lint = long long;
    int val;
    ModInt() : val(0) {}
    void _setval(lint v) { v = (v % mod) + mod; val = v >= mod ? v - mod : v; }
    ModInt(lint v) { _setval(v); }
    ModInt operator+(const ModInt &x) const { return ModInt((lint)val + x.val); }
    ModInt operator-(const ModInt &x) const { return ModInt((lint)val - x.val); }
    ModInt operator*(const ModInt &x) const { return ModInt((lint)val * x.val); }
    ModInt operator/(const ModInt &x) const { return ModInt((lint)val * x.inv().val); }
    ModInt operator-() const { return ModInt(-val); }
    ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    bool operator==(const ModInt &x) { return val == x.val; }
    bool operator!=(const ModInt &x) { return val != x.val; }
    friend ostream &operator<<(ostream &os, const ModInt &x) { os << x.val;  return os; }

    lint power(lint n) const {
        ModInt ans(1), tmp(val);
        while (n) {
            if (n & 1) ans *= tmp;
            tmp *= tmp;
            n /= 2;
        }
        return ans.val;
    }
    ModInt inv() const { return this->power(mod - 2); }
    
    ModInt fac() const {
        static vector<ModInt> facs;
        int l0 = facs.size();
        if (l0 > this->val) return facs[this->val];

        facs.resize(this->val + 1);
        for (int i = l0; i <= this->val; i++) facs[i] = (i == 0 ? 1 : facs[i - 1] * i);
        return facs[this->val];
    }

    ModInt doublefac() const {
        lint k = (this->val + 1) / 2;
        if (this->val & 1) return ModInt(k * 2).fac() / ModInt(2).power(k) / ModInt(k).fac();
        else return ModInt(k).fac() * ModInt(2).power(k);
    }

    ModInt nCr(const ModInt &r) const {
        if (this->val < r.val) return ModInt(0);
        return this->fac() / ((*this - r).fac() * r.fac());
    }
};
using mint = ModInt<1000000007>;


SegTree<pint> segtree(602, pint(1000, 0), [](pint a, pint b){return pint(min(a.first, b.first), max(a.second, b.second));});

mint dp[602][602];

mint solve(int l, int r)
{
    mint ans = 0;
    pint pall = segtree.query(l, r + 1);

    int ca = avi[r] - avi[l - 1];
    if (pall.first < l || pall.second > r || (ca & 1)) return ans;

    ans = mint(max(ca - 1, 0)).doublefac();

    FOR(i, l + 1, r) // lからiまでが連結
    {
        pint left = segtree.query(l, i + 1);
        if (left.second > i) continue;
        int c2 = avi[r] - avi[i];
        if (c2 & 1) continue;

        ans -= dp[l][i] * mint(max(c2 - 1, 0)).doublefac();
    }
    dp[l][r] = ans;
    return ans * mint(max(avi[l - 1] + avi[N * 2] - avi[r] - 1, 0)).doublefac();
}

int main()
{
    cin >> N >> K;
    con.resize(N * 2 + 1);

    avi[0] = 0;
    FOR(i, 1, N * 2 + 1) avi[i] = 1;
    

    REP(_, K)
    {
        int A, B;
        cin >> A >> B;
        con[A] = B;
        con[B] = A;
        avi[A] = avi[B] = 0;
        segtree.update(A, pint(B, B));
        segtree.update(B, pint(A, A));
    }
    REP(i, N * 2) avi[i + 1] += avi[i];

    mint ans = 0;
    FOR(l, 1, 2 * N) FOR(r, l + 1, 2 * N + 1) ans += solve(l, r);
    cout << ans << endl;
}
