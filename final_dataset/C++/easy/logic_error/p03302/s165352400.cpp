#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;



int main() {

  int n, m, d;
  cin >> n >> m >> d;

  int num = 0;
  if(d==0) {
    num = n;
  }
  else {
    for(int i = 0; i < n; ++i) {
      if(i-d >= 0) num += 1;
      if(i+d <  n) num += 1;
    }
  }

  cout << (double)(m-1)*((2*(n-d))/(n*n)) << endl;

}
