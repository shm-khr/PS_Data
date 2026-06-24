#include<stdio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<math.h>
using namespace std;

template <class T>
class _Point{
public:
	T x;
	T y;
	_Point(){}
	_Point(T _x, T _y) :x(_x), y(_y){}
	_Point(const _Point & v) :x(v.x), y(v.y){}

	const _Point operator + (const _Point & v)
	{
		return _Point(x+v.x,y+v.y);
	}
	const _Point operator - (const _Point & v)
	{
		return _Point(x - v.x, y - v.y);
	}
	T abs() const {
		return sqrt(x*x + y*y);
	}
	_Point unit() const{
		T len = abs();
		return _Point(x / len, y / len);
	}
	T operator*(const _Point &v) const
	{
		return x * v.x + y * v.y;
	}
	const _Point operator*(const T &len) const
	{
		return _Point(len * x, len * y);
	}
};
typedef double R;
typedef _Point<R> Point;
typedef Point Vector;

int main(){
	std::istream & c_in = cin;

	Point p, p1, p2;
	c_in >> p1.x >> p1.y >> p2.x >> p2.y;
	Vector P12(p2 - p1);
	Vector e12(P12.unit());

	int q;
	c_in >> q;
	for (int i = 0; i < q; ++i)
	{
		Point p;
		c_in >> p.x >> p.y;
		p = p - p1;
		R projection = p*e12;
		Vector b(projection*(e12.x), projection*(e12.y));
		Point X(p1 + b);
		Point Q(X);
		Vector px = X - p;
		Q = Q + px;
		cout << fixed << setprecision(10) << Q.x << " " << Q.y << endl;
	}
}