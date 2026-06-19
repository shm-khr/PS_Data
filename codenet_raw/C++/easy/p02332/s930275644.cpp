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



int main(){
    ll n,k;
    cin>>n>>k;
    ll p=1;
    if(n>k){cout<<0<<endl return 0;}
    for(int i=0;i<n;i++){
        p*=k;
        k--;
        p%=MOD;
    }
    cout<<p<<endl;
    
    
    return 0;
}
