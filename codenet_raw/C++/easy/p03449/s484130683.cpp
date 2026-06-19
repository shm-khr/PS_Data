#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, i, j;
  cin >> n;
  vector<vector<int>> A(2, vector<int>(n)), dp(2, vector<int>(n + 1));
  for (i = 0; i < 2; i++) {
    for (j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
  dp[0][0] = 0;
  for (j = 0; j < n; j++) {
    dp[0][j + 1] = dp[0][j] + A[0][j];
  }

  for (j = 0; j < n; j++) {
    dp[1][j + 1] =
        max(dp[0][j] + A[0][j] + A[0][j + 1], dp[0][j] + A[0][j] + A[1][j]);
  }
  cout << dp[1][n - 1] + A[1][n - 1] << "\n";
  return 0;
}