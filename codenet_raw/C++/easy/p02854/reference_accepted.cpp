#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long int> A(N), L(N + 1, 0), R(N + 1, 0);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) L.at(i + 1) = L.at(i) + A.at(i);
  for (int i = N - 1; i >= 0; i--) R.at(i) = R.at(i + 1) + A.at(i);
  long long int ans = 1000000000000000000;
  for (int i = 0; i <= N; i++) ans = min(ans, abs(L.at(i) - R.at(i)));
  cout << ans << endl;
}