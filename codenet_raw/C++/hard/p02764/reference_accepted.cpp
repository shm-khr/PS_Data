#include <bits/stdc++.h>
using namespace std;

using Real = long double;
using Point = complex< Real >;
const Real EPS = 1e-8, PI = acos(-1);

Point operator*(const Point &p, const Real &d) {
  return Point(real(p) * d, imag(p) * d);
}

inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }

istream &operator>>(istream &is, Point &p) {
  Real a, b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}


struct Line {
  Point a, b;

  Line() = default;

  Line(Point a, Point b) : a(a), b(b) {}

  Line(Real A, Real B, Real C)
  {
    if(eq(A, 0)) a = Point(0, C / B), b = Point(1, C / B);
    else if(eq(B, 0)) b = Point(C / A, 0), b = Point(C / A, 1);
    else a = Point(0, C / B), b = Point(C / A, 0);
  }
};

Line g(Point a, Point b) {
    Point c = (a + b) / Point(2, 0);
    Point d = c + (b - a) * Point(0, 1);
    return Line(c, d);
}


struct Circle {
  Point p;
  Real r;

  Circle() = default;

  Circle(Point p, Real r) : p(p), r(r) {}
};

Circle h(Point a, Real acin, Point b, Real bcin) {
    assert(acin < bcin);
    Point ac = Point(acin, 0);
    Point bc = Point(bcin, 0);
    Point c = (a * ac + b * bc) / (ac + bc);
    Point d = (-a * ac + b * bc) / (-ac + bc);
    Real r = abs(c - d) / 2;
    return Circle((c + d) / Point(2, 0), r);
}

using Points = vector< Point >;
using Lines = vector< Line >;
using Circles = vector< Circle >;

Real cross(const Point &a, const Point &b) {
  return real(a) * imag(b) - imag(a) * real(b);
}

Real dot(const Point &a, const Point &b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

Point projection(const Line &l, const Point &p) {
  double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + (l.a - l.b) * t;
}

Real distance(const Line &l, const Point &p) {
  return abs(p - projection(l, p));
}

bool intersect(const Line &l, const Line &m) {
  return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS;
}

bool intersect(const Circle &c, const Line &l) {
  return distance(l, c.p) <= c.r + EPS;
}

int checker(Circle c1, Circle c2) {
  if(c1.r < c2.r) swap(c1, c2);
  Real d = abs(c1.p - c2.p);
  if(c1.r + c2.r < d) return 4;
  if(eq(c1.r + c2.r, d)) return 3;
  if(c1.r - c2.r < d) return 2;
  if(eq(c1.r - c2.r, d)) return 1;
  return 0;
}

bool intersect(Circle c1, Circle c2) {
    int tmp = checker(c1, c2);
    return 1 <= tmp and tmp <= 3;
}

Point crosspoint(const Line &l, const Line &m) {
  Real A = cross(l.b - l.a, m.b - m.a);
  Real B = cross(l.b - l.a, l.b - m.a);
  if(eq(abs(A), 0.0) && eq(abs(B), 0.0)) return m.a;
  return m.a + (m.b - m.a) * B / A;
}


pair< Point, Point > crosspoint(const Circle &c, const Line l) {
  Point pr = projection(l, c.p);
  Point e = (l.b - l.a) / abs(l.b - l.a);
  if(eq(distance(l, c.p), c.r)) return {pr, pr};
  double base = sqrt(c.r * c.r - norm(pr - c.p));
  return {pr - e * base, pr + e * base};
}

pair< Point, Point > crosspoint(const Circle &c1, const Circle &c2) {
  Real d = abs(c1.p - c2.p);
  Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
  Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
  Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
  Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
  return {p1, p2};
}

int N, K;
Points P;
vector<int> c;
vector<long double> r;
Circles C;
Points p;
void input() {
    cin >> N >> K;
    P.resize(N);
    c.resize(N);
    C.resize(N);
    r.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i] >> c[i];
    }
}


void f(vector<int> v) {
    sort(v.begin(), v.end(), [](auto const &l, auto const &r) {
        return c[l] < c[r];
    });
    if(c[v[0]] == c[v[2]]) {
        auto l1 = g(P[v[0]], P[v[1]]);
        auto l2 = g(P[v[1]], P[v[2]]);
        if(intersect(l1, l2)) {
            p.push_back(crosspoint(l1, l2));
        }
    } else if(c[v[0]] == c[v[1]]) {
        auto l1 = g(P[v[0]], P[v[1]]);
        auto c1 = h(P[v[1]], c[v[1]], P[v[2]], c[v[2]]);
        if(intersect(c1, l1)) {
            auto tmp = crosspoint(c1, l1);
            p.push_back(tmp.first);
            p.push_back(tmp.second);
        }
    } else if(c[v[1]] == c[v[2]]) {
        auto l1 = g(P[v[1]], P[v[2]]);
        auto c1 = h(P[v[0]], c[v[0]], P[v[1]], c[v[1]]);
        if(intersect(c1, l1)) {
            auto tmp = crosspoint(c1, l1);
            p.push_back(tmp.first);
            p.push_back(tmp.second);
        }
    } else {
        auto c1 = h(P[v[0]], c[v[0]], P[v[1]], c[v[1]]);
        auto c2 = h(P[v[1]], c[v[1]], P[v[2]], c[v[2]]);
        if(intersect(c1, c2)) {
            auto tmp = crosspoint(c1, c2);
            p.push_back(tmp.first);
            p.push_back(tmp.second);
        }
    }
}

void solve() {
    p.clear();
    long double ans = 1e9;
    for(int i = 0; i < N; i++) {
        p.push_back(P[i]);
        for(int j = 0; j < i; j++) {
            p.push_back((P[i]*c[i]+P[j]*c[j]) / Point(c[i]+c[j],0));
            for(int k = 0; k < j; k++) {
                f({i, j, k});
            }
        }
    }
    for(auto tmp : p) {
        vector<long double> v;
        for(int i = 0; i < N; i++) {
            v.push_back(abs(tmp - P[i]) * c[i]);
        }
        sort(v.begin(), v.end());
        ans = min(ans, v[K-1]);
    }
    cout << fixed << setprecision(20) << ans << endl;
}

int main() {
    input();
    solve();
    return 0;
}
