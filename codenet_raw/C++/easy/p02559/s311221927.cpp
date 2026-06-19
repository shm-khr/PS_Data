//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"
//#include "atcoder/fenwicktree.hpp"
using namespace std;
//using namespace atcoder;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

template<typename T>
class BIT{
public:
    int n;
    vector<T> bit; // 1-indexed

    BIT():n{0}{}
    BIT(int n_in):n{n_in}{
        bit.assign(n+1,0);
    }

    void init_u(){
        for(int i=1;i<n;i++) bit[i+(i&-i)]+=bit[i];
    }

    void add(int k,T w){
        if(k<=0) return;
        for(int i=k;i<=n;i+=i&-i) bit[i]+=w;
    }

    //(0,k]
    T sum(int k) const{
        T res=0;
        for(int i=k;i>0;i-=i&-i) res+=bit[i];
        return res;
    }

    //(l,r] 累積和区間と同じ
    T secsum(int l,int r) const{
        return sum(r)-sum(l);
    }

    //各要素は非負整数とする
    //w->w+1でupper_bound
    int lower_bound(T w) const{
        if(sum(n)<w) return n+1; //範囲外
        int idx=0,r=1;
        while(r<n) r<<=1;
        for(int len=r;len>0;len>>=1){
            if(idx+len<n && bit[idx+len]<w){
                w-=bit[idx+len];
                idx+=len;
            }
        }
        return idx+1;
    }
};

int main(){
    int n,q; cin>>n>>q;
    BIT<ll> bit{n};
    rep(i,n) cin>>bit.bit[i+1];
    bit.init_u();
    rep(_,q){
        int t,l,r; cin>>t>>l>>r;
        if(t==0){
            bit.add(l+1,r);
        }
        else{
            printf("%lld\n",bit.secsum(l,r));
        }
    }
}
