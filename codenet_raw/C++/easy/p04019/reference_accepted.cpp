#include <bits/stdc++.h>
using namespace std;

int main() {
  string X;
  int w=0,e=0,n=0,s=0;

  cin >> X;
  for(int i=0;i<X.size();++i){
    if(X.at(i) == 'W'){
      w = 1;
    }else if(X.at(i) == 'E'){
      e = -1;
    }else if(X.at(i) == 'N'){
      n = 1;
    }else{
      s = -1;
    }
  }
  if(e+w == 0 && n+s == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
