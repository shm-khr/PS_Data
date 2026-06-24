#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A[i];

  int ans = 0;
  sort(A.begin(), A.end());
  rep(i, (int)A.size()) {
    ans++;
    int a = A[i];
    bool b = false;
    for (int j = i+1; j < (int)A.size(); j++) {
      if (!b && A[j] == a) {
        b = true;
        ans--;
      }
      if (A[j] %a == 0) {
        A.erase(A.begin()+j);
        j--;
      }
    }
  }
  cout << ans << endl;
}