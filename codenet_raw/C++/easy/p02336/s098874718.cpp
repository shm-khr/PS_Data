#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<math.h>
#include<numeric>
#include<cassert>
#include<random>
#include<deque>
#include<chrono>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
const ll E=1e18+7;
#define F first
#define S second
#define MK make_pair
const ll MOD=1000000007;

vector<vector<ll>> c;

void mk_c(){
    c.resize(2100);
    for(int i=1;i<2100;i++){
        c[i].resize(2100);
        c[i][0]=1;
        c[i][i]=1;
        for(int t=1;t<i;t++){
            c[i][t]=(c[i-1][t-1]+c[i-1][t])%MOD;
        }
    }
}

int main(){
    ll n,k;
    cin>>n>>k;
    n-=k;
    if(n<0){cout<<0<<endl; return 0;}
    mk_c();
    cout<<c[n+k-1][k-1]<<endl;
    
    
    
    
    return 0;
}
