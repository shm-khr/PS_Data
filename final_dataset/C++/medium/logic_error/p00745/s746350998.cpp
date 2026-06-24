#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;

bool tolerant_eq(double a, double b){ return abs(a - b) < EPS; }

struct Point {
	double x, y;
	explicit Point(const double &x = 0.0, const double &y = 0.0) :
		x(x), y(y)
	{ }

	static Point invalid(){
		double qnan = numeric_limits<double>::quiet_NaN();
		return Point(qnan, qnan);
	}
	bool is_valid() const { return !(isnan(x) || isnan(y)); }

	Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
	Point &operator+=(const Point &p){ return *this = *this + p; }
	Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
	Point &operator-=(const Point &p){ return *this = *this - p; }
	Point operator*(double s) const { return Point(x * s, y * s); }
	Point &operator*=(double s){ return *this = *this * s; }
	Point operator/(double s) const { return Point(x / s, y / s); }
	Point &operator/=(double s){ return *this = *this / s; }

	bool operator==(const Point &p) const { return x == p.x && y == p.y; }
	bool operator!=(const Point &p) const { return x != p.x || y != p.y; }
	bool operator<(const Point &p) const {
		return (x == p.x) ? (y < p.y) : (x < p.x);
	}
};

Point operator*(double s, const Point &p){ return p * s; }

bool tolerant_eq(const Point &a, const Point &b){
	return tolerant_eq(a.x, b.x) && tolerant_eq(a.y, b.y);
}
double abs(const Point &p){ return sqrt(p.x * p.x + p.y * p.y); }
Point unit(const Point &p){ return p / abs(p); }
Point ortho(const Point &p){ return Point(-p.y, p.x); }
double cross(const Point &a, const Point &b){ return a.x * b.y - a.y * b.x; }
double dot(const Point &a, const Point &b){ return a.x * b.x + a.y * b.y; }
int ccw(const Point &a, const Point &b, const Point &c){
	Point d = b - a, e = c - a;
	if(cross(d, e) > 0.0){ return 1; }
	if(cross(d, e) < 0.0){ return -1; }
	if(dot(d, e) < 0.0){ return 2; }
	if(abs(d) < abs(e)){ return -2; }
	return 0;
}

struct Polygon : public vector<Point> {
	Polygon() : vector<Point>() { }
	explicit Polygon(size_t s, const Point &p = Point()) :
		vector<Point>(s, p)
	{ }

	static Polygon invalid(){ return Polygon(); }
	bool is_valid() const { return size() > 0; }
};

Polygon convex_hull(vector<Point> p){
	int n = p.size(), k = 0;
	sort(p.begin(), p.end());
	Polygon res(2 * n);
	for(int i = 0; i < n; ++i, ++k){
		while(k >= 2 && ccw(res[k - 2], res[k - 1], p[i]) <= 0){ --k; }
		res[k] = p[i];
	}
	for(int i = n - 2, t = k + 1; i >= 0; --i, ++k){
		while(k >= t && ccw(res[k - 2], res[k - 1], p[i]) <= 0){ --k; }
		res[k] = p[i];
	}
	res.resize(k - 1);
	return res;
}

int convex_contains(const Polygon &g, const Point &p){
	int n = g.size();
	Point q = (g[0] + g[n / 2] + g[2 * n / 3]) / 3.0;
	int left = 0, right = n;
	while(left + 1 < right){
		int c = (left + right) / 2;
		Point p_q = p - q, c_q = g[c] - q;
		if(cross(g[left] - q, c_q) > 0.0){
			if(cross(g[left] - q, p_q) > 0.0 && cross(c_q, p_q) < 0.0){
				right = c;
			}else{
				left = c;
			}
		}else{
			if(cross(g[left] - q, p_q) < 0.0 && cross(c_q, p_q) < 0.0){
				left = c;
			}else{
				right = c;
			}
		}
	}
	right %= n;
	if(cross(g[left] - p, g[right] - p) < 0.0){ return 0; }  // out
	if(cross(g[left] - p, g[right] - p) > 0.0){ return -1; } // in
	return -1; // on line
}

int main(){
	ios_base::sync_with_stdio(false);
	cout << setiosflags(ios::fixed) << setprecision(10);
	while(true){
		int m, n;
		cin >> m >> n;
		if(m == 0 && n == 0){ break; }
		vector<Point> init(m), poll(n * 3);
		for(int i = 0; i < m; ++i){ cin >> init[i].x >> init[i].y; }
		for(int i = 0; i < n; ++i){
			cin >> poll[i].x >> poll[i].y;
			poll[i + n] = poll[i] + Point(2 * EPS, 0.0);
			poll[i + n + n] = poll[i] + Point(EPS, EPS);
		}
		n *= 3;
		vector<Point> fixed(1, init[0]);
		vector<int> fccw(1, 0);
		for(int i = 1; i + 1 < m; ++i){
			vector<Point> pollArea(3);
			pollArea[0] = fixed.back();
			pollArea[1] = init[i];
			pollArea[2] = init[i + 1];
			Polygon triangle = convex_hull(pollArea);
			vector<Point> cand;
			cand.push_back(fixed.back());
			cand.push_back(init[i + 1]);
			for(int j = 0; j < n; ++j){
				if(convex_contains(triangle, poll[j])){
					cand.push_back(poll[j]);
				}
			}
			if(cand.size() == 0){ continue; }
			Polygon convex = convex_hull(cand);
			int cs = convex.size(), k = 0;
			for(int j = 0; j < cs; ++j){
				if(convex[j] == fixed.back()){ k = j; break; }
			}
			if(convex[(k + 1) % cs] == init[i + 1]){
				int begin = (k + cs - 1) % cs, end = (k + 1) % cs;
				for(int j = begin; j != end; j = (j + cs - 1) % cs){
					fixed.push_back(convex[j]);
					fccw.push_back(-1);
				}
			}else{
				int begin = (k + 1) % cs, end = (k + cs - 1) % cs;
				for(int j = begin; j != end; j = (j + 1) % cs){
					fixed.push_back(convex[j]);
					fccw.push_back(1);
				}
			}
		}
		fixed.push_back(init.back());
		fccw.push_back(0);
		while(true){
			vector<Point> nfixed(1, fixed[0]);
			vector<int> nfccw(1, 0);
			bool modified = false;
			for(int i = 1; i + 1 < fixed.size(); ++i){
				Point a = nfixed.back(), b = fixed[i], c = fixed[i + 1];
				if(fccw[i] == ccw(a, b, c)){
					nfixed.push_back(b);
					nfccw.push_back(fccw[i]);
					continue;
				}
				modified = true;
				vector<Point> pollArea(3);
				pollArea[0] = a; pollArea[1] = b; pollArea[2] = c;
				Polygon triangle = convex_hull(pollArea);
				vector<Point> cand;
				for(int j = 0; j < m; ++j){
					if(convex_contains(triangle, poll[j])){
						cand.push_back(poll[j]);
					}
				}
				if(cand.size() == 0){ continue; }
				Polygon convex = convex_hull(cand);
				int k = 0, cs = convex.size();
				for(int j = 0; j < cs; ++j){
					if(convex[j] == a){ k = j; break; }
				}
				if(convex[(k + 1) % cs] == c){
					int begin = (k + cs - 1) % cs;
					for(int j = begin; j != begin; j = (j + cs - 1) % cs){
						nfixed.push_back(convex[j]);
						nfccw.push_back(-1);
					}
				}else{
					int begin = (k + 1) % cs;
					for(int j = begin; j != begin; j = (j + 1) % cs){
						nfixed.push_back(convex[j]);
						nfccw.push_back(1);
					}
				}
			}
			nfixed.push_back(fixed.back());
			nfccw.push_back(0);
			if(!modified){ break; }
			fixed = nfixed;
			fccw = nfccw;
		}
		double answer = 0.0;
		for(int i = 1; i < fixed.size(); ++i){
			answer += abs(fixed[i] - fixed[i - 1]);
		}
		cout << answer << endl;
	}
	return 0;
}