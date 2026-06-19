#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
#define ALL(x) (x).begin(), (x).end()

int N;
vector<int> a;

vector<pint> ans;

constexpr int DMAX = 1 << 10;

void reshape()
{
    set<int> X, Y;
    for (auto p : ans) X.insert(p.first), Y.insert(p.second);
    unordered_map<int, int> xz, yz;
    for (auto x : X)
    {
        int n = xz.size();
        xz[x] = n * DMAX;
    }
    for (auto y : Y)
    {
        int n = yz.size();
        yz[y] = n * DMAX;
    }
    vector<pint> ret;
    for (auto p : ans) ret.emplace_back(xz[p.first], yz[p.second]);

    ans = ret;
}

int main()
{
    cin >> N;
    a.resize(N);
    cin >> a;
    vector<int> acc(N + 1);
    REP(i, N) acc[i + 1] = acc[i] + (a[i] == 90 ? 1 : -1);
    if (acc.back() != 4)
    {
        puts("-1");
        return 0;
    }
    int mini = min_element(acc.begin(), acc.end()) - acc.begin();

    ans.emplace_back(0, 0);
    ans.emplace_back(DMAX, 0);
    ans.emplace_back(DMAX, DMAX);
    ans.emplace_back(0, DMAX);
    ans.emplace_back(0, 0);
    int np = (N - 4) / 2;
    int D = DMAX / 2;
    REP(now, N)
    {
        int d = a[(mini + now) % N];
        if (d == 270 or np <= 0)
        {
            now++;
            continue;
        }
        pint &A = ans[now];
        pint &B = ans[now + 1];
        pint X = make_pair((A.first + B.first) / 2, (A.second + B.second) / 2);
        pint Y = make_pair((A.first + B.first) / 2, (A.second + B.second) / 2);
        if (A.second == B.second)
        {
            if ((A.first < B.first) xor (d == 90))
            {
                Y.second -= D, B.second -= D;
            }
            else
            {
                Y.second += D, B.second += D;
            }
        }
        else
        {
            if ((A.second < B.second) xor (d == 90))
            {
                Y.first += D, B.first += D;
            }
            else
            {
                Y.first -= D, B.first -= D;
            }
        }
        ans.insert(ans.begin() + now + 1, Y);
        ans.insert(ans.begin() + now + 1, X);
        now++;
        D /= 2;
        if (D < 1)
        {
            reshape();
            D = DMAX / 2;
        }
    }

    vector<pint> ret(N);
    REP(i, N) ret[(mini + i) % N] = ans[i];
    REP(i, N) printf("%d %d\n", ret[i].first, ret[i].second);
}
