#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int(i)=0;(i)<(n);(i)++)

int main() {
  int n;
  cin >> n;
  vector<double> a(n);
  rep(i, n) cin >> a[i];
  double total = 0;
  vector<double> subSum(n);
  rep(i, n) {
    if(i == 0) subSum[i] = a[i];
    else subSum[i] = subSum[i-1] + a[i];
  }
  total = subSum[n-1];
  double half = total / 2;
  auto it = upper_bound(subSum.begin(), subSum.end(), half);
  double ans_1 = LLONG_MAX;
  double ans_2 = LLONG_MAX;
  if(it != subSum.begin()) ans_1 = (half - *prev(it)) * 2;
  int dist = distance(subSum.begin(), it) + 1;
  long long limit = *it - dist;
  if((*it-half)*2<=limit) ans_2 = (*it-half) * 2;
  cout << min(ans_1, ans_2) << endl;
}