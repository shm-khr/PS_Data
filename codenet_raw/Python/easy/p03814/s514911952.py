#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int min_a = s.size(), max_z = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == 'A' and i < min_a) {
      min_a = i;
    }
    if (s.at(i) == 'Z' and i > max_z) {
      max_z = i;
    }
  }
  cout << max_z - min_a + 1 << endl;
}