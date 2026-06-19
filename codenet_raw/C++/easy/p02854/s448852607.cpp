#include <bits/stdc++.h>
using namespace std;

void main_()
{
    int64_t N;
    vector<int64_t> As;
    cin >> N;
    copy_n(istream_iterator<int64_t>(cin), N, back_inserter(As));

    auto total_len = accumulate(begin(As), end(As), 0LL);
    int64_t left = 0;
    int64_t middle = 0;
    int64_t right = 0;
    for (int i = 0, len = 0; i < N; ++i) {
        left = len;
        len += As[i];
        if (len >= total_len / 2) {
            middle = As[i];
            right = total_len - len;
            break;
        }
    }

    int ans1 = min(left + middle - right, right + middle - left);

    cout << ans1 << endl;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    main_();
    return 0;
}
