#include <algorithm>
#include <complex>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    a.push_back(t);
  }
  int count = 0;
  while (true) {
    bool divOperation = false;
    for (size_t i = 0; i < a.size(); ++i) {
      if (!divOperation && a[i] % 2 == 0) {
        a[i] = a[i] / 2;
        divOperation = true;
      }
    }
    if (divOperation) {
      ++count;
    } else {
      break;
    }
  }
  cout << count << endl;
  return 0;
}
