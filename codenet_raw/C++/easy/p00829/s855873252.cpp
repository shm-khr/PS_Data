#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    while (n--) {
        ll e = 0;
        loop (8, i) {
            string s; cin >> s;
            e += stoi("0x"+s, nullptr, 16);
            e %= 1ll<<32;
        }
        string s; cin >> s;
        cout << hex << (e ^ stoi("0x"+s, nullptr, 16));
    }
    return 0;
}