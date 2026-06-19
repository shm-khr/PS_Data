#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

const int N  =2e5+10;

int n;
ll a[N][2];
void solve(){
    cin >> n;
    ll ans = 0;
    for(int i=0;i<n;++i)
        cin >> a[i][0] >> a[i][1];
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
            ans = max(ans , abs(a[i][0]-a[j][0]) + abs(a[i][1] - a[j][1]));
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t =1;
    while(t--)
        solve();
    return 0;
}

