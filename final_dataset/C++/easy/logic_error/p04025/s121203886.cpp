#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N, a[100];
  cin >> N;

  double min = 101, max = -101;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (a[i] < min) min = a[i];
    if (a[i] > max) max = a[i];
  }

  int x = (max + min) / 2.0 + 0.5;
  
  int ans = 0;
  for (int i = 0; i < N; i++) ans += (a[i] - x) * (a[i] - x);

  cout << ans << endl;

  return 0;
}