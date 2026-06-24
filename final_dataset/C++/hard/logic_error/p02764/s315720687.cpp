#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <cctype>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-8;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

class Point{
    public: 
    long double x,y;
    int c = 0;
    Point(long double x = 0.0, long double y = 0.0): x(x), y(y) {}
    Point operator + (const Point &p) const { return Point(x+p.x, y+p.y); }
    Point operator - (const Point &p) const { return Point(x-p.x, y-p.y); }
    Point operator * (const long double &a) const { return Point(x*a, y*a); }
    Point operator / (const long double &a) const { return Point(x/a, y/a); }
    bool operator < (const Point &p) const { return (x != p.x ? x < p.x : y < p.y); }
    bool operator == (const Point &p) const { return fabsl(x - p.x) < EPS && fabsl(y - p.y) < EPS; }
    long double abs() const { return sqrt(norm()); }
    long double norm() const { return x*x + y*y; }
    long double dot(Point &p) const { return x*p.x + y*p.y; }
    long double cross(Point &p) const { return x*p.y - y*p.x; }   
};

typedef Point Vector;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<Point> meats(n);
    for(int i=0;i<n;++i) {
        cin >> meats[i].x >> meats[i].y >> meats[i].c;
    }

    long double ans = 1e10;
    for(int i=0;i<=n-k;++i) {
        long double lowx = -1e10, highx = 1e10;
        for(int z=0;z<100;++z) {
            long double midx = (lowx+highx) / 2.0, tmpans = 0.0, tmpans2 = 0.0;
            for(int j=i;j<i+k;++j) {
                tmpans = max(tmpans, meats[j].c * sqrt((midx - meats[j].x) * (midx - meats[j].x) + (0.0 - meats[j].y) * (0.0 - meats[j].y)));
            }
            for(int j=i;j<i+k;++j) {
                tmpans2 = max(tmpans2, meats[j].c * sqrt((midx+EPS - meats[j].x) * (midx+EPS - meats[j].x) + (0.0 - meats[j].y) * (0.0 - meats[j].y)));
            }
            if(tmpans < tmpans2) {
                highx = midx;
            } else {
                lowx = midx;
            }
        }

        long double lowy = -1e10, highy = 1e10, midx = lowx, midy = 0.0, tmpans = 0.0; 
        for(int z=0;z<100;++z) {
            long double midy = (lowy+highy) / 2.0,  tmpans2 = 0.0;
            tmpans = 0.0;
            for(int j=i;j<i+k;++j) {
                tmpans = max(tmpans, meats[j].c * sqrt((midx - meats[j].x) * (midx - meats[j].x) + (midy - meats[j].y) * (midy - meats[j].y)));
            }
            for(int j=i;j<i+k;++j) {
                tmpans2 = max(tmpans2, meats[j].c * sqrt((midx - meats[j].x) * (midx - meats[j].x) + (midy+EPS - meats[j].y) * (midy+EPS - meats[j].y)));
            }
            if(tmpans < tmpans2) {
                highy = midy;
            } else {
                lowy = midy;
            }
        }
        ans = min(ans, tmpans);
    }
 
    cout << fixed << setprecision(10) << ans << endl;

}
