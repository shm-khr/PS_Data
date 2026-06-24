#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i= 0; i<n; i++)

int main(){
    int N,M;
    vector<ll>::iterator max;
    size_t maxIndex;
    ll ans=0;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,M){
        max= max_element(A.begin(),A.end());
        maxIndex = distance(A.begin(),max);
        A[maxIndex] /= 2;
    }
    rep(i,N){
        ans += A.back();
        A.pop_back();
    }
    cout << ans <<endl; 
    return 0;
}