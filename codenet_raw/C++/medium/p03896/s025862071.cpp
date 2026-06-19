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

signed main(){
    int N;cin>>N;
    if(N%2==0){
        cout<<-1<<endl;
        
    }
    else{
        rep(i,N){
            rep(j,N-1){
                if(j)cout<<" ";
                cout<<(i+j+1)%N+1;
            }cout<<endl;
        }
    }
    return 0;
}
