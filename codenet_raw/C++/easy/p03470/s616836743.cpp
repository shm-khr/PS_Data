#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

//bucketmethod

int main() {
  int n;
  int cnt=0;
  cin >>n;
  vector<int> d(n);
  rep(i,n) cin>>d[i];
  vector<int> bucket(n,0);
  rep(i,n) bucket[d[i]]++; //d[i]が同じなら同じbucketに入る
  rep(i,n){
    if(bucket[i]>0) cnt++;
  }
  cout << cnt <<endl;
}
