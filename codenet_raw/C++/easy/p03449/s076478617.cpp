#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,c;
  int sum1=0,sum2=0;
  cin >> n;
  vector<vector<int>> aij(2,vector<int>(n));
  for(int i=0;i<n;i++){ cin >> aij.at(0).at(i); sum1+=aij.at(0).at(i);}
  for(int i=0;i<n;i++){ cin >> aij.at(1).at(i); sum2+=aij.at(1).at(i);}
  vector<int> candies(n);
  candies.at(0) = sum2;
  for(int i=1;i<n;i++) candies.at(i) = sum2-candies.at(i-1);
  for(int i=0;i<n;i++) candies.at(i) += aij.at(0).at(i);
  int tmp = candies.at(0);
  for(int i=0;i<n;i++){
    if(tmp < candies.at(i)) tmp = candies.at(i);
  }
  if(tmp>=(sum1+aij.at(1).at(n-1)) cout << tmp << endl;
  else cout << (sum1+aij.at(1).at(n-1)) << endl;
  
/*  c=aij.at(0).at(0);
  for(int i=0;i<n;i++){
    sum1 -= aij.at(0).at(i);
    if((sum1+aij.at(1).at(n-1))<sum2){
      c+=sum2; break;
    }
    else if((sum1+aij.at(1).at(n-1))>sum2){
      c+=aij.at(0).at(i+1);
      sum2-=aij.at(1).at(i);
    }
    else if(sum1 == 0){
      c+=sum2; break;
    }
    else{
      c+=aij.at(0).at(i+1);
      sum2-=aij.at(1).at(i);
    }
    }*/
  
}