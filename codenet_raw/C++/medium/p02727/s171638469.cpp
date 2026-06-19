#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    int X = in(),Y = in(),A = in(),B = in(),C = in();
    vector<ll> p(A);
    vector<ll> q(B);
    vector<ll> r(C);
    REP(i,A)p[i] = in<ll>();
    REP(i,B)q[i] = in<ll>();
    REP(i,C)r[i] = in<ll>();
    sort(ALL(p),greater<>());
    sort(ALL(q),greater<>());
    sort(ALL(r),greater<>());
    int ps = X-1;
    int qs = Y-1;
    int rs = 0;
    while(1){
        if(ps == -1 || qs == -1){
            if(ps != -1){
                if(q[qs] < r[rs]){
                    q[qs] = r[rs];
                    rs++;
                    qs--;
                }else{
                    break;
                }
            }else if(qs != -1){
            if(p[ps] < r[rs]){
                p[ps] = r[rs];
                rs++;
                ps--;
            }else{
                break;
            }
            }else{
                break;
            }
        }else{
        if(p[ps] > q[qs]){
            if(q[qs] < r[rs]){
                q[qs] = r[rs];
                rs++;
                qs--;
            }else{
                break;
            }
        }else{
            if(p[ps] < r[rs]){
                p[ps] = r[rs];
                rs++;
                ps--;
            }else{
                break;
            }
        }
        }
    }
    ll answer = 0;
    REP(i,X)answer += p[i];
    REP(i,Y)answer += q[i];
    cout << answer << "\n";
}