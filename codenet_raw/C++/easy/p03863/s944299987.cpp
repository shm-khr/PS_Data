#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
const int MOD = 1000000007;
const int INF = numeric_limits<int>::max() / 2;
typedef pair<int,int> P;
using Graph = vector<vector<int>>;



signed main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  bool ok = false;
  int N = S.size();
  for(int i=0;i<=N-3;i++){
    if(S[i] != S[i+2])ok = true;
  }
  if(ok){
    if(N % 2 == 1){
      cout << "First" << endl;
    }
    else{
      cout << "Second" << endl;
    }
  }
  else{
    cout << "Second" << endl;
  }

}