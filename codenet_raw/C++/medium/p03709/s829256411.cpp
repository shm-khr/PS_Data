#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 200005;
const int INF = 1e9;
const int MOD = 66662333;
int n;
int L[MAXN], R[MAXN], a[MAXN], cnt;
int f[MAXN], sum[MAXN], ans;

PII s[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &s[i].first, &s[i].second), a[i] = s[i].second;
    sort(a + 1, a + n + 1), cnt = unique(a + 1, a + n + 1) - a - 1;
    for (int i = 1; i <= n; i++)
        s[i].second = lower_bound(a + 1, a + cnt + 1, s[i].second) - a;

    sort(s + 1, s + n + 1), L[n + 1] = INF;
    for (int i = 1; i <= n; i++)
        R[i] = max(R[i - 1], s[i].second);
    for (int i = n; i; i--)
        L[i] = min(L[i + 1], s[i].second);
    for (int i = 1; i <= n; i++)
        s[i] = make_pair(L[i], R[i]);

    sort(s + 1, s + n + 1), f[0] = sum[0] = 1;
    for (int i = 1, j = 0; i <= n; i++) {
        while (s[j].second < s[i].first - 1)
            j++;
        f[i] = (sum[i - 1] - (!j ? 0 : sum[j - 1]) + MOD) % MOD;
        sum[i] = (sum[i - 1] + f[i]) % MOD;
    }
    for (int i = 1; i <= n; i++)
        if (s[i].second == cnt)
            ans = (ans + f[i]) % MOD;
    printf("%d", ans);
    return 0;
}
