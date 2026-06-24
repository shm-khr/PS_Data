#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define inf (1LL<<60)
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
template<typename T>
T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}

int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll> > a;
    ll s = 0;
    rep(i,n){
        ll c,d;
        cin >> c >> d;
        if(c<d){
            s += d-c;
            a.push_back(make_pair(d,inf));
        }else{
            a.push_back(make_pair(c,d));
        }
    }
    ll sm = s;
    if(s==0){
        cout << 0 << " " << 1 << endl;
        return 0;
    }
    sort(a.begin(),a.end());
    ll k = 0;
    ll pid = -1;
    ll id = -1;
    ll sk = 0;
    ll sk1 = 0;
    rep(i,n){
        if(s>=a[i].first){
            k++;
            s-=a[i].first;
        }else{
            sk = s;
            sk1 = sk - a[i].first;
            break;
        }
    }
    ll x = k;
    ll y = n;
    ll z = gcd(k,n);
    x /=z;
    y /=z;
    ll xx,yy,zz;
    rep(i,n){
        if(a[i].second==inf){    
            if(i<k){
                if(sk1 + a[i].first >0){
                    xx = a[i].first*k + sk1+a[i].first;
                    yy = a[i].first*n;
                }else{
                    continue;
                }
            }else{
                if(sk >0){
                    xx = a[i].first*k + sk;
                    yy = a[i].first*n;
                }else{
                    continue;
                }
            }
            zz = gcd(xx,yy);
            xx /=zz;
            yy /=zz;
            if((__uint128_t)(x) * (__uint128_t)(yy) < (__uint128_t)(y) * (__uint128_t)(xx) ){
                x = xx;
                y = yy;
            }
        }else{
            if(i<k){
                if(sk1 + a[i].first-a[i].second >0){
                    xx = a[i].second*k + sk1+a[i].first-a[i].second;
                    yy = a[i].second*n;
                }else{
                    continue;
                }
            }else{
                if(sk - a[i].first+a[i].second >0){
                    xx = a[i].second*k + sk - a[i].first+a[i].second;
                    yy = a[i].second*n;
                }else{
                    continue;
                }
            }
            zz = gcd(xx,yy);
            xx /=zz;
            yy /=zz;
            if((__uint128_t)(x) * (__uint128_t)(yy) < (__uint128_t)(y) * (__uint128_t)(xx) ){
                x = xx;
                y = yy;
            }
        }
    }
    cout << x << " " << y << endl;
    
    return 0;
}