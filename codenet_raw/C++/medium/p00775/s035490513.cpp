// #define USE_CPP11
// #define USE_PRINTF

#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <complex>
#include <memory>
#include <sstream>

#ifdef USE_CPP11
#include <unordered_map>
#include <unordered_set>
#include <functional>
#endif

#define PRINT(obj) cout << obj << endl
#define REP(i, n) for(int (i) = 0; (i) < (n); i++)
#define SPACE " "

typedef long long ll;

const int INF = 1e9 + 10;

using namespace std;

namespace Scanner {
#ifdef USE_PRINTF
  int    nextInt()    { int    d; scanf("%d" , &d); return d; }
  float  nextFloat()  { float  f; scanf("%f" , &f); return f; }
  double nextDouble() { double f; scanf("%lf", &f); return f; }  
  string nextString() { string s; scanf("%s" , &s); return s; }
  ll     nextll()     { ll     l; scanf("%ll", &l); return l; }
#else
  int    nextInt()    { int    d; cin >> d; return d; }
  float  nextFloat()  { float  f; cin >> f; return f; }
  double nextDouble() { double f; cin >> f; return f; }  
  string nextString() { string s; cin >> s; return s; }
  ll     nextll()     { ll     l; cin >> l; return l; }
#endif

  string getLine() { 
    string input;
    getline(cin, input);
    return input;
  }
};

namespace myLibrary {
  vector<string> split(const string& str, char delim) {
    vector<string> ret;
    size_t current = 0, found;
    while ((found = str.find_first_of(delim, current)) != string::npos) {
      ret.push_back(string(str, current, found - current));
      current = found + 1;
    }
    ret.push_back(string(str, current, str.size() - current));
    return ret;
  }
  
#ifdef USE_CPP11
  ///
  /// higher-order functional
  /// This is something like map in haskell, python, etc.
  /// Sample usage:
  ///   vector<int> a = {1, 2, 3, 4, 5};
  ///   vector<int> b = myLibrary::_Map<int, int>(a, [](int n){
  ///     return n * n;
  ///   });
  /// Result:
  ///   b = 1, 4, 9, 16, 25
  ///
  template<typename T_IN, typename T_OUT, class Functor>
  vector<T_OUT> _Map(vector<T_IN> src, Functor func) {
    vector<T_OUT> ret;
    for (int i = 0; i < src.size(); i++) {
      ret.push_back(func(src[i]));
    }
    return ret;
  }
#endif

};

struct Point {
public:
  int y, x;
  Point(int y, int x): y(y), x(x) { }
  Point() { }
};

/// BEGIN //////////////////////////////////////////////////////////

int main() {

  while (true) {
    int r = Scanner::nextInt();
    int n = Scanner::nextInt();

    if (r + n == 0) {
      break;
    }

    int height[41] = { 0 };

    int ymax = 0;
    for (int i = 0; i < n; i++) {
      int xl = Scanner::nextInt() + 20;
      int xr = Scanner::nextInt() + 20;
      int h  = Scanner::nextInt();

      ymax = max(ymax, h);
      for (int x = xl; x < xr; x++) {
        height[x] = max(height[x], h);
      }      
    }  

    double lt = 0, ht = ymax;

    for (int i = 0; i < 100; i++) {
      double mt = (lt + ht) / 2;
      double y = mt - r;

      bool isOK = true;

      for (int i = 0; i < 41; i++) {
        double dsq = 0;
        if (i < 20) {
          dsq = (i - 19) * (i - 19) + (height[i] - y) * (height[i] - y);
        } else {
          dsq = (i - 20) * (i - 20) + (height[i] - y) * (height[i] - y);
        }
        if (dsq < r * r) {
          isOK = false;
          break;
        }
      }

      if (isOK) {
        lt = mt;
      } else {
        ht = mt;
      }
    }

    printf("%.15f\n", ht);

  }

  return 0;
}

/// END   //////////////////////////////////////////////////////////