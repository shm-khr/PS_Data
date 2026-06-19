#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#define REP(i, a, b) for(int i = (a); i < int(b); ++i)
#define rep(i, n) REP(i, 0, n)
#define ALL(x) begin(x), end(x)

constexpr double EPS = 1e-7;

struct point {
	double x, y;
	explicit point(double x_ = 0, double y_ = 0):x(x_), y(y_) {}

	inline point operator+(const point &p) const {
		return point(x + p.x, y + p.y);
	}

	inline point operator-(const point &p) const {
		return point(x - p.x, y - p.y);
	}

	inline point operator*(double s) const {
		return point(x * s, y * s);
	}

	inline bool operator<(const point &p) const {
		return x + EPS < p.x || (abs(x - p.x) && y + EPS < p.y);
	}

	inline bool operator==(const point &p) const {
		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
	}
};

double angle(const point &p) {
	return atan2(p.y, p.x);
}

double dot(const point &a, const point &b) {
	return a.x * b.x + a.y * b.y;
}

double cross(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

double norm(const point &p) {
	return p.x * p.x + p.y * p.y;
}

int ccw(const point &a, point b, point c) {
	b = b - a;
	c = c - a;
	const double t = cross(b, c);
	if(t > EPS) return 1;
	if(t < -EPS) return -1;
	if(dot(b, c) < 0) return 2;
	if(norm(b) < norm(c)) return -2;
	return 0;
}

typedef vector<point> polygon;

struct segment {
	point a, b;
	segment(const point &a_, const point &b_):a(a_), b(b_) {}
};

bool intersect(const segment &s, const point &p) {
	return ccw(s.a, s.b, p) == 0;
}

bool intersect(const segment &s, const segment &t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0
		&& ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

point crosspoint(const segment &s, const segment &t) {
	const double tmp = cross(s.b - s.a, t.b - t.a);
	if(abs(tmp) < EPS) {
		if(intersect(s, t.a)) return t.a;
		if(intersect(s, t.b)) return t.b;
		if(intersect(s, s.a)) return s.a;
		return s.b;
	}
	return t.a + (t.b - t.a) * (cross(s.b - s.a, s.b - t.a) / tmp);
}

bool contain(const polygon &P, const point &p) {
	const int n = P.size();
	bool res = false;
	rep(i, n) {
		point v1 = P[i] - p, v2 = P[(i + 1) % n] - p;
		if(v1.y > v2.y) swap(v1, v2);
		if(v1.y < EPS && EPS < v2.y && cross(v1, v2) > EPS) res = !res;
		if(abs(cross(v1, v2)) < EPS && dot(v1, v2) < EPS) return true;
	}
	return res;
}


struct edge {
	int to;
	double theta;
	bool used = false;
	edge(int to_, double theta_):to(to_), theta(theta_) {}
};

vector<vector<edge>> arrangement(const vector<segment> &segments, vector<point> &points) {
	const int n = segments.size();
	points.clear();

	rep(i, n) {
		const auto &s1 = segments[i];

		rep(j, i) {
			const auto &s2 = segments[j];
			if(intersect(s1, s2)) {
				points.emplace_back(crosspoint(s1, s2));
			}
		}
	}

	sort(ALL(points));
	points.erase(unique(ALL(points)), points.end());

	const int V = points.size();
	vector<vector<edge>> G(V);

	for(const auto &s : segments) {
		vector<pair<double, int>> vs;
		rep(i, V) {
			if(intersect(s, points[i])) {
				vs.emplace_back(norm(s.a - points[i]), i);
			}
		}

		sort(ALL(vs));
		REP(i, 1, vs.size()) {
			const int v = vs[i].second;
			const int u = vs[i - 1].second;
			G[v].emplace_back(u, angle(points[u] - points[v]));
			G[u].emplace_back(v, angle(points[v] - points[u]));
		}

	}

	return G;
}

bool solve(const vector<segment> &segments) {
	vector<point> points;
	auto G = arrangement(segments, points);

	const int n = G.size();
	const point monster(0, 0);

	rep(i, n) {
		rep(j, G[i].size()) {
			int v = i;
			int e_idx = j;
			polygon P;

			while(true) {
				auto &e = G[v][e_idx];
				if(e.used) break;

				e.used = true;
				P.emplace_back(points[v]);
				v = e.to;

				double base_angle = e.theta - M_PI;
				if(base_angle < -M_PI) base_angle += 2 * M_PI;

				double min_angle = INT_MAX;
				rep(k, G[v].size()) {
					double theta = G[v][k].theta - base_angle;
					if(theta < EPS) theta += 2 * M_PI;
					if(theta < min_angle) {
						min_angle = theta;
						e_idx = k;
					}
				}
			}

			if(P.size() >= 3 && contain(P, monster)) return true;
		}
	}

	return false;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int n; cin >> n && n;) {
		vector<segment> segments;
		segments.reserve(n);

		rep(i, n) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			segments.emplace_back(point(x1, y1), point(x2, y2));
		}

		cout << (solve(segments) ? "yes" : "no") << endl;
	}

	return EXIT_SUCCESS;
}