#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n = 0;
    int ans = 0;
    vector<int> p(n);
    cin >> n;
    for (size_t i : p)
    {
        cin >> p[i];
        ans += p[i];
    }
    for (size_t i : p)
    {
        ans -= (*max_element(p.begin(), p.end())) / 2;
    }
    cout << ans << endl;
    return 0;
}