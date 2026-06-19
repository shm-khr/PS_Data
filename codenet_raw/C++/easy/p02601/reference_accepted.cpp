#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int A,B,C,K;

int main(){
    cin>>A>>B>>C>>K;

    int cnt=0;
    while(cnt<=K && A>=B){
        cnt++;
        B*=2;
    }
    while(cnt<=K && B>=C){
        cnt++;
        C*=2;
    }

    if(cnt>K) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}