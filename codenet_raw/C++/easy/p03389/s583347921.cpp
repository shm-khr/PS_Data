#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  vector<int> A(3);
  for(int i = 0; i < 3; ++i) cin >> A[i];
  int ans = 0;
  while(A[0] != A[2]){
    if(A[0] != A[1]){
      A[0] += 2;
      ++ans;
      sort(A.begin(), A.end());
    }
    if(A[1] != A[2]){
      --A[2];
      ++ans;
      sort(A.begin(), A.end());
    }
  }
  cout << ans << endl;
 return 0;
}
