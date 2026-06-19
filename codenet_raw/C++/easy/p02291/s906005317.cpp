#include <numeric>
#include <iomanip>
typedef std::vector<double> VecD;
#define rep(n) for(int i=0;i<n;i++)
#define PB push_back

class Point;
// void send(FILE* f, char* p, int n);
// void send(std::ostream* f, char* p, int n);
const Point projection(const Point &p1, const Point &p2);

class Point{
friend const double operator*(const Point&, const Point&);
template <class T> friend const Point operator*(const T&, const Point&);
template <class T> friend const Point operator*(const Point&, const T&);
friend const Point operator+(const Point&, const Point&);
template <class T> friend const Point operator+(const T&, const Point&);
template <class T> friend const Point operator+(const Point&, const T&);
friend const Point operator-(const Point&);
friend const Point operator-(const Point&, const Point&);
template <class T> friend const Point operator-(const T&, const Point&);
template <class T> friend const Point operator-(const Point&, const T&);
// template <class W> friend W& operator<<(W&, const Point&);
friend std::ostream& operator<<(std::ostream&, const Point&);

public:
	Point(){};
	Point(VecD v){
		point = v;
	}
	VecD point;
};

const double operator*(const Point &p0, const Point &p1){ return inner_product( p0.point.begin(), p0.point.end(), p1.point.begin(), 0); }
template <class T>
const Point operator*(const T &a, const Point &p1){
	VecD v;
	for(VecD::const_iterator iter1=p1.point.begin();iter1!=p1.point.end();iter1++) v.PB(*iter1 * a);
	const Point p(v);
	return p;
}
template <class T>
const Point operator* (const Point &p, const T &a){return a*p;}
const Point operator+(const Point &p0, const Point &p1){
	VecD v;
	VecD::const_iterator iter0 = p0.point.begin();
	for(VecD::const_iterator iter1=p1.point.begin();iter1!=p1.point.end();iter1++){
		v.PB(*iter0 + *iter1);
		iter0++;
	}
	const Point p(v);
	return p;
}
template <class T>
const Point operator+(const T &a, const Point &p1){
	VecD v;
	for(VecD::const_iterator iter1=p1.point.begin();iter1!=p1.point.end();iter1++){
		v.PB(*iter1 + a);
	}
	const Point p(v);
	return p;
}
template <class T>
const Point operator+(const Point &p1, const T &a){return a+p1;}
const Point operator-(const Point &p1){return (-1)*p1;}
const Point operator-(Point &p0, Point &p1){ return p0+(-p1); }
template <class T>
const Point operator-(const T &a, Point &p1){ return a+(-p1); }
template <class T>
const Point operator-(Point &p1, const T &a){return (-a)+p1;}

// template <class W>
// W& operator<<(W& w, const Point& p){
// 	for(VecD::const_iterator iter=p.point.begin(); iter!=p.point.end(); iter++){
// 		char c[8];
// 		sprintf(c, "%lf", *iter);
// 		send(w, c, 1);
// 	}
// 	return w;
// }

const Point projection(const Point &p1, const Point &p2){
	// cout << p1*p2 << endl;
	return ((p1*p2) / (p1*p1)) * p1;
}

std::ostream& operator<<(std::ostream &os, const Point &p){
	os << std::fixed << std::setprecision(10) << p.point[0] << " " << std::fixed << std::setprecision(10) << p.point[1] << std::endl;
}
// void send(FILE* f, char* p, int n){
// 	for (int i=0; i<n; i++){
// 		fputs(p++, f);
// 	}
// }
// void send(std::ostream* o, char* p, int n){
// 	for (int i=0; i<n; i++){
// 		// fputs(p++, f);
// 		o << *p;
// 	}
// }

#include <iostream>
#include <vector>
using namespace std;

int main(void){
	double xp0, yp0, xp1, yp1; cin >> xp0 >> yp0 >> xp1 >> yp1;
	unsigned int q; cin >> q;
	VecD v0; v0.PB(xp0); v0.PB(yp0); Point p0(v0);
	VecD v1; v1.PB(xp1); v1.PB(yp1); Point p1(v1);
	Point _p0 = p0-p0;
	Point _p1 = p1-p0;
	rep(q){
		double xp2, yp2; cin >> xp2 >> yp2;
		VecD v2; v2.PB(xp2); v2.PB(yp2); Point p2(v2);
		Point _p2 = p2-p0;
		Point _ref = (projection(_p1, _p2) - _p2) * 2;
		Point ref = _ref+p2;
		cout << ref << endl;
	}
}