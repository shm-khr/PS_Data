#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum=0, pre=0;
  cin >> N;
  vector<int> vec(N);
  
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  
  for(int i=0; i<N; i++){
    if(i+1<N){
      if(vec.at(i)==vec.at(i+1)){
        if(pre==vec.at(i+1)){
          pre=vec.at(i+1);
          i++;
          continue;
        }
        else{
          pre=vec.at(i);
          sum++;
          i++;
          continue;
        }
      }
      else{
        sum++;
        pre=vec.at(i+1);
      }
    }
  }
  cout << sum+1 << endl;
}
