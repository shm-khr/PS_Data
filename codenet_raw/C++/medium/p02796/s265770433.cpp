#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    long long int now = -1999;
    int ans = 0;
    vector<pair<long long int,long long int>> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, l;
        cin >> x >> l;
        v.push_back(make_pair(x+l,x-l));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (now <= v[i].second) {
            ans++;
            now = v[i].first;
        }
    }

    cout << ans << endl;
}
