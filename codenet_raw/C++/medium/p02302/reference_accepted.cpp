#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<cstdlib>
#include<algorithm>

using namespace std;
#define pb push_back
#define mp make_pair
#define SZ(x) (int)(x).size()

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<LL, LL> pll;

const double eps = 1e-10;
const double PI = acos(-1.0);
//const double PI = 3.14159265358979323846264338327950288419716939937510
int dcmp(const double &x) { if (fabs(x) < eps) return 0; return x < 0 ? -1 : 1; }
const int MOD = 1e9 + 7;
const int INF = 2e9;
const double INF_d = 1e64;

template<class T> 
T qmod(T a, T b){ T ret = 1; while (b){ if (b & 1) ret *= a; b >>= 1; a *= a; } return ret; }
template<class T>
T gcd(T a, T b){ return !b ? a : gcd(b, a % b); }
template<class T>
T ex_gcd(T a, T b, T &x, T &y){
    if (!b){ x = 1, y = 0; return a; }
    T t, ret;
    ret = ex_gcd(b, a % b, x, y);
    t = x, x = y, y = t - a / b * y;
    return ret;
}
template<class T>
T inv(T t, T p){ return t == 1 ? 1 : (p - p / t) * inv(p % t, p) % p; }
// head

typedef double db;

struct point{
    db x, y;
    point(){}
    point(db a, db b): x(a), y(b){}
    point operator + (const point &p){ return point(x + p.x, y + p.y); }
    point operator - (const point &p){ return point(x - p.x, y - p.y); }
    point operator * (const db &k){ return point(x * k, y * k); }
    point operator / (const db &k){ return point(x / k, y / k); }
    db operator ^ (const point &p){ return x * p.y - y * p.x; }
    db operator * (const point &p){ return x * p.x + y * p.y; }
    bool operator == (const point &p){ return !dcmp(x - p.x) && !dcmp(y - p.y); }
    bool operator != (const point &p){ return dcmp(x - p.x) || dcmp(y - p.y); }
    bool operator < (const point &p){ return x == p.x ? y < p.y : x < p.x; }
    void read(){
        scanf("%lf%lf", &x, &y);
    }
    void print(){
        printf("%.10f %.10f\n", x, y);
    }
    point rotate(db &ang){ return point(x * cos(ang) - y * sin(ang), y * cos(ang) + x * sin(ang)); }
    point norm() { return point(-y, x); }
    db len() { return sqrt(x * x + y * y); }
    db len2(){ return x * x + y * y; }
};

point err = point(INF_d, INF_d);

point proj_SP(point A, point B, point P){ // projection point of P in segment AB
    point AB = B - A, AP = P - A;
    return A + AB * (AP * AB / AB.len2());
}

point refl_SP(point A, point B, point P){ // reflection point of P int segment AB
    return proj_SP(A, B, P) * 2 - P;
}

struct line{
    point p[2], u;
    line(){}
    line(point s, point t){
        p[0] = s, p[1] = t;
        u = p[1] - p[0];
    }
    point get_point(double t){
        return point(p[0] + u * t);
    }
};

bool parallel(line L1, line L2){ // check whether two lines L1 and L2 are parallel
    return !dcmp(L1.u ^ L2.u);
}

bool orthogonal(line L1, line L2){ // check whether two lines L1 and L2 are orthogonal
    return !dcmp(L1.u * L2.u);
}

pair<bool, point> inter_LL(line L1, line L2){ // calculate the intersection of two lines L1 and L2
    if (parallel(L1, L2)) return mp(false, err);
    double t = ((L2.p[0] - L1.p[0]) ^ L2.u) / (L1.u ^ L2.u);
    return mp(true, L1.get_point(t));
}

bool one_dimention_check(db a, db b, db c, db d){ // check whether two one-dimention segments has intersection
    if (dcmp(a - b) > 0) swap(a, b);
    if (dcmp(c - d) > 0) swap(c, d);
    return dcmp(b - c) >= 0 && dcmp(a - d) <= 0; 
}

bool check_SS(point A, point B, point C, point D){ // check whether two segments AB and CD has intersection
    bool flag = one_dimention_check(A.x, B.x, C.x, D.x) && one_dimention_check(A.y, B.y, C.y, D.y);
    double a = dcmp((A - C) ^ (D - C)), b = dcmp((B - C) ^ (D - C)),
            c = dcmp((C - A) ^ (B - A)), d = dcmp((D - A) ^ (B - A));
    return flag && dcmp(a * b) <= 0 && dcmp(c * d) <= 0;
}
// calculate the intersection point of two segments, first check and then call inter_LL to get the cross point

bool inmid(db a, db b, db c){  // check whether a <= c <= b
    return dcmp(dcmp(b - c) * dcmp(a - c)) <= 0; 
}

bool inmid(point A, point B, point P){ // check whether point P is in the rectangle of segment AB
    return inmid(A.x, B.x, P.x) && inmid(A.y, B.y, P.y);
}

db dis_SP(point A, point B, point P){ // the minimum distance from a point P to segment AB
    point p_proj = proj_SP(A, B, P);
    if (inmid(A, B, p_proj)) return (P - p_proj).len();
    else return min((P - A).len(), (P - B).len());
}

db dis_SS(point A, point B, point C, point D){ // the minimum distance from two segments AB and CD
    db res = INF_d;
    if (check_SS(A, B, C, D)) res = 0;
    res = min(res, dis_SP(A, B, C));
    res = min(res, dis_SP(A, B, D));
    res = min(res, dis_SP(C, D, A));
    res = min(res, dis_SP(C, D, B));
    return res;
}

db poly_Area(point *poly, int n){ // calc the area of a simple polygon poly, n is the number of points.
    //the points should be in clockwise or counter_clockwise.
    db res = 0.0;
    for (int i = 1; i < n - 1; i++){
        res += (poly[i] - poly[0]) ^ (poly[i + 1] - poly[0]);
    }
    return fabs(res) / 2;
}

bool is_Convex(point *poly, int n){ // check whether a polygon is a convex polygon. Make sure points are in counter-clockwised order.
    poly[n] = poly[0];
    if (n < 3) return 1;
    for (int i = 1; i < n; i++){
        int tmp_dir = dcmp((poly[i] - poly[i - 1]) ^ (poly[(i + 1) % n] - poly[i]));
        if (tmp_dir < 0) return 0;
    }
    return 1;
}

bool is_PonS(point A, point B, point P){ // check whether a point P is on a segment AB
    return inmid(A, B, P) && !dcmp((P - A) ^ (B - A));
}

int is_PinPoly(point *poly, int n, point P){ // check the position relation of a point and polygon.
    // 0: outside, 1: on a segment, 2: inside
    int pd = 0;
    for (int i = 0; i < n; i++){
        point u = poly[i], v = poly[(i + 1) % n];
        if (is_PonS(u, v, P)) return 1;
        if (dcmp(u.y - v.y) > 0) swap(u, v);
        if (dcmp(u.y - P.y) >= 0 || dcmp(v.y - P.y) < 0) continue;
        if (dcmp((u - v) ^ (P - v)) < 0) pd ^= 1;
    }
    return pd << 1;
}

bool cmpxy(const point &a, const point &b){ // compare x first, then y. from small -> large
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

bool cmpyx(const point &a, const point &b){ // compare x first, then y. from small -> large
    return a.y == b.y ? a.x < b.x : a.y < b.y;
}

int get_convexhull(point *p, int n, point *ch){ // get the convexhull of given polygon p
    // pay attention to when m = 0, 1, 2 as the return value
    sort(p, p + n, cmpyx); // may be changed by the requirement of problem
    int m = 0;
    for (int i = 0; i < n; i++){
        while (m > 1 && dcmp((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) < 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i--){
        while (m > k && dcmp((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) < 0) m--;
        ch[m++] = p[i];
    }
    if (n > 1) m--;
    return m;
}

db convexhull_diameter(point *ch, int n){ // calculate the diameter of a give convexhull
    if (n < 2) return 0;
    int is, js; is = js = 0;
    for (int i = 0; i < n; i++){
        is = ch[i] < ch[is] ? i : is;
        js = ch[js] < ch[i] ? i : js;
    }
    int i = is, j = js;
    db ret = (ch[is] - ch[js]).len();
    do{
        if (dcmp((ch[(i + 1) % n] - ch[i]) ^ (ch[(j + 1) % n] - ch[j])) > 0){
            j = (j + 1) % n;
        }
        else{
            i = (i + 1) % n;
        }
        ret = max(ret, (ch[i] - ch[j]).len());
    } while (i != is || j != js);
    return ret;
}

int convexhull_cut(point *ch, int n, point P, point Q, point *new_ch){
    int m = 0;
    for (int i = 0; i < n; i++){
        int d1 = dcmp((Q - P) ^ (ch[i] - P)), d2 = dcmp((Q - P) ^ (ch[(i + 1) % n] - P));
        if (d1 >= 0) new_ch[m++] = ch[i];
        if (d1 * d2 < 0) new_ch[m++] = inter_LL(line(P, Q), line(ch[i], ch[(i + 1) % n])).second;
    }
    return m;
}

const int N = 1e5 + 7;
int n, m, num;
point p[N], x, ch[N], y;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        p[i].read();
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        x.read(), y.read();
        int num = convexhull_cut(p, n, x, y, ch);
        printf("%.12f\n", poly_Area(ch, num));
    }
    return 0;
}
