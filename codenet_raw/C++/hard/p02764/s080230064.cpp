#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <bitset>

#include <random>

using namespace std;
void dout() { cerr << endl; }
typedef long long ll;
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

using ll = long long;
using pii = pair<ll, ll>;
using ld = long double;
using pll = pair<long long, long long>;

void precalc() {}

//#define solvsh
//#define multi

#ifdef solvsh

void solve() {

}

#else
typedef vector<int> vi;
#define INF 0x3f3f3f3f
#define FOR(i, n) for(int i = 0; i < n; i++)
template<class T>
T rnd(T l,T r){	//[l,r)
    using D = uniform_int_distribution<T>;
    static random_device rd;
    static mt19937 gen(rd());
    return D(l,r-1)(gen);
}
const int MAXN = 1000;

int n;
int k;
ld eps = 1e-7;
ld coef[MAXN];
pair<ld, ld> pts[MAXN];

ld ff(ld x, ld y) {
    vector<ld> times;
    for (int i = 0; i < n; ++i) {
        ld dx = abs(x - pts[i].first);
        ld dy = abs(y - pts[i].second);
        times.push_back(coef[i] * sqrt(dx * dx + dy * dy));
    }

    sort(times.begin(), times.end());

    return times[k - 1];
}

vector<ld > xx;
vector<ld > yy;

ld calc2(ld x, ld left, ld right){

    while (true){

        ld ml = (2 * left + right) / 3;
        ld mr = (left + 2 * right) / 3;

        ld vall = ff(x, ml);
        ld valr = ff(x, mr);

        if (vall > valr){
            left = ml;
        } else {
            right = mr;
        }
        if (abs(left - right) < eps)
            break;
    }

    return ff(x, (left + right) / 2);
}

ld f(ld x){
    ld answr = 1e18;
    for (int i = 0; i < n - 1; ++ i){
        answr = min(answr, calc2(x, yy[i], yy[i + 1]));
    }

    return answr;
}


ld calc(ld left, ld right){
    while (true){

        ld ml = (2 * left + right) / 3;
        ld mr = (left + 2 * right) / 3;

        ld vall = f(ml);
        ld valr = f(mr);

        if (vall > valr){
            left = ml;
        } else {
            right = mr;
        }

        if (abs(left - right) < eps)
            break;
    }

    return f((left + right) / 2);
}

void solve() {
    cin >> n;
    cin >> k;


    for (int i = 0 ; i < n; ++ i){
        ld x, y, c;
        cin >> x >> y >> c;
        pts[i] = {x, y};
        coef[i] = c;
        xx.push_back(x);
        yy.push_back(y);
    }

    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());

    ld answr = 1e18;

    if (n == 1)
        answr = 0;

    for (int i = 0; i < n - 1; ++ i){
        answr = min(answr, calc(xx[i], xx[i + 1]));
    }

    cout << answr;
}

#endif


void multisolve() {
    int t;
    cin >> t;

    while (t--)
        solve();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(20);

    precalc();


#ifdef multi
    multisolve();
#else
    solve();
#endif

#ifdef LOCAL
    //cout << '\n' << (double)clock() / CLOCKS_PER_SEC << '\n';
#endif
}