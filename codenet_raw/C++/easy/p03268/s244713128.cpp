#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >=0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
 
typedef long long ll;
#define INF 1e9
 
 
int main(){
  int N, K;
  cin >> N >> K;
  ll cnt = 0;
  if(K%2){
    for(int i = K; i <= N; i+=K){
      cnt++; // I== j== k のとき
      cnt += 3*((i-1)/K); // i == j の時
      cnt += 3*((i-1)/K); // j==k の時
      int box = (i-1)/K-1;
      cnt += 6* (box*(box+1)/2);
    }
  }
  else{
    for(int i = K/2; i <= N; i+=K/2){
      cnt++; // i== j== k のとき
      cnt += 3 * ((i-K/2)/K); // i==j の時
      cnt += 3 * ((i-K/2)/K); // j==k のとき
      int box = (i-K/2)/K -1;
      cnt += 6*(box*(box+1)/2);
    }
  }
  cout << cnt << endl;
  return 0;
}