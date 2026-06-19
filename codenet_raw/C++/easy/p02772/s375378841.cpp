#include <bits/stdc++.h>

using namespace std;
const int N = 600000;

int n;
string s;
map<string, int> mm;
vector<pair<int, string> > c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a % 2 == 0)
        {
            if (a % 3 == 0 || a % 5 == 0) continue;
            cout << "DENIED";
            return 0;
        }
    }
    cout << "APPROVED";
}
