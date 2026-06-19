#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef bitset<16> BS;

const ll MOD = 1E+09 + 7;
const ll INF = 1E18;
const int MAX_N = 100;

int N;

int A[MAX_N + 1], B[MAX_N + 2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    for (int i = 1; i <= N; i++) {
        A[i] += A[i - 1];
    }
    for (int i = N; i >= 1; i--) {
        B[i] += B[i + 1];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, A[i] + B[i]);
    }

    /*
    for (int i = 1; i <= N; i++) {
        cout << "i = " << i << ", A = " << A[i] << ", B = " << B[i] << "\n";
    }
    */

    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "i = " << i << ", j = " << j << ", dp = " << dp[i][j] << "\n";
        }
    }
    */

    cout << ans << "\n";

    return 0;
}