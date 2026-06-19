#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,M,T;

int v[1000];

int dp[2][1000];
int dp2[3][1000];
signed main(){
    cin>>N>>M>>T;
    fill_n(v,1000,INT_MIN);
    rep(i,N){
        int a;cin>>a;
        chmax(v[a%T],a);
    }

    fill_n(*dp,2*1000,INT_MIN);
    dp[0][0]=0;

    while(M){
        fill_n(*dp2,3*1000,INT_MIN);
        rep(i,2)rep(j,T)rep(k,T){
            chmax(dp2[i+1][(j+k)%T],dp[i][j]+v[k]);
            chmax(dp2[i][j],dp[i][j]);
        }
        fill_n(*dp,2*1000,INT_MIN);
        rep(i,3){
            rep(j,T){
                chmax(dp[(i+1-M%2)/2][j],dp2[i][j]);
            }
        }

        vint vv(T,INT_MIN);
        rep(i,T){
            chmax(vv[i*2%T],v[i]*2);
        }
        rep(i,T)v[i]=vv[i];

        M/=2;
    }

    vint latte(T);
    rep(i,T)latte[i]=dp[0][i];
    for(int i=T-2;i>=0;i--)chmax(latte[i],latte[i+1]);

    int Q;cin>>Q;
    while(Q--){
        int a,b;
        cin>>a>>b;

        if(latte[a]>=b*T){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}