#include <complex>
#include <iomanip>
#include <iostream>

using namespace std;

typedef complex<double> Point;

Point reflection(Point a, Point b) {
  return conj(b / a) * a;
}

int main() {
  double x, y;
  cin >> x >> y;
  complex<double> p1(x, y);
  cin >> x >> y;
  complex<double> p2(x, y);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> x >> y;
    complex<double> p(x, y);
    auto refl = reflection(p2 - p1, p - p1);
    cout << fixed << setprecision(15) << refl.real() << " " << refl.imag() << endl;
  }
}