#include <bits/stdc++.h>
#define H ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
using namespace std;
const ll  mod = 3e7;

string bin(int x){
    string s = "00000";
    int i = 4;
    while (x){
        s[i--] = (x % 2) + '0';
        x /= 2;
    }
    return s;
}

string s, str;
int f[1000006], arr[1000006];
int getNxt(int len, char c){
    while (len && s[len] != c){
        len = f[len - 1];
    }
    if (s[len] == c)
        len++;
    return len;
}

void computeF(){
    f[0] = 0;
    for (int i = 1; i < s.size(); i++){
        f[i] = getNxt(f[i - 1], s[i]);
    }
}

void KMP(){
    computeF();
    int k = 0, ans = 0;
    for (int i = 0; i < str.size(); i++){
        k = getNxt(k, str[i]);
        arr[k]++;
    }

}

int main()
{
    H
    int n, k;
    cin >> n >> k;
    int x, idx, mn = 0x3f3f3f3f;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x < mn){
            mn = x;
            idx = i;
        }
    }
    int ans1 = 0, ans2 = 0;
    if (idx <= k - 1) ans1 = 1 + (n - k + 1 > 1 ? ((n - k + 1) / 3) + 1 : 0);
    else ans1 = (idx + 1) / 3 + 1 + (n - idx) / 3 + 1;
    if (idx >= n - k) ans2 = 1 + (n - k + 1 > 1 ? (n - k + 1) / 3 + 1 : 0);
    else ans2 = (idx + 1) / 3 + 1 + (n - idx) / 3 + 1;
    cout << min(ans1, ans2);
    //cout << '\n' << ans1 << ' ' << ans2 << ' ' << idx;
    return 0 ;
}