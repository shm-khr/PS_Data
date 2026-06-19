#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int a = 0;
  cin >> s;
  
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'o') a++;
  }
  
  cout << a << endl;
  
  return 0;
}