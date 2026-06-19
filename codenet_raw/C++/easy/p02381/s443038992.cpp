#include <iostream>      /* printf */
#include <cmath>       /* sin */
#include <iomanip>

#define PI 3.14159265
using namespace std;

int main ()
{

  int n;

  while (1) {
    cin >> n;
    if (n == 0) {
      exit(0);
    }

    double s[1000];

    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }

    double m = 0;
    for (int i = 0; i< n; i++) {
      m += s[i];
    }
    m /= n;
    double alpha = 0;
    for (int i=0; i<n; i++) {
      alpha += pow(s[i] - m, 2);
    }
    alpha = sqrt(alpha/n);
    cout << fixed << setprecision(6) << alpha << endl;

  }
  return 0;
}