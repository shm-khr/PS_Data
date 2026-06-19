#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  string s;
  cin >> s;
  long n=s.size();
  vector<int>a(26);
  rep(i,n){
    a.at(s.at(i)-'a')++;
  }
  long ans=n*(n-1)/2+1;
  rep(i,26){
    if(a.at(i)>=2){
      ans-=a.at(i)*(a.at(i)-1)/2;
    }
  }
  
    cout<<ans<<endl;
  
  
}