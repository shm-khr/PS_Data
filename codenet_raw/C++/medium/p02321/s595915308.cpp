#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;
using namespace std;

ll inf=(1ll<<32);
pair<ll,ll> pl[1<<20];
int v[40],w[40];
int main(){
    int n,ww;
    cin>>n>>ww;
    rep(i,n) cin>>v[i]>>w[i];
    //half split
    int n2=n/2;
    rep(i,1<<n2){
        ll sw=0,sv=0;
        rep(j,n2){
            if(i>>j&1){
                sw+=w[j];sv+=v[j];
            }
        }
        pl[i]=mp(sw,sv);
    }
    sort(pl,pl+(1<<n2));
    int m=1;
    rep(i,1<<n2){
        if(pl[m-1].second<pl[i].second) pl[m++]=pl[i];
    }
    ll ans=0;
    rep(i,1<<(n-n2)){
        ll sw=0,sv=0;
        rep(j,n-n2){
            if(i>>j&1){
                sw+=w[n2+j];sv+=v[n2+j];
            }
        }
        if(sw<=ww){
            ll tv=(lower_bound(pl,pl+m,mp(ww-sw,inf))-1)->second;
            ans=max(ans,sv+tv);
        }
    }
    cout<<ans<<endl;
    return 0;
}