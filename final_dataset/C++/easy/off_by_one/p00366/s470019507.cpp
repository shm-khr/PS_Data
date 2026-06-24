#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int ans = 0;
  int N, temp[10100], ma = 0, i, j,temp3;
  cin>>N;

  
  ma = temp[0];
  for(i = 0; i < N; i++){
    cin>>temp[i];
    ma = max(ma, temp[i]);
  }
  for(i = 0; i < N; i++){
    temp3 = ma;
    for(j = 1; j * j <= ma; j++){
      if(ma%j == 0){
	if(j >= temp[i])temp3 = min(j - temp[i], temp3);
	if(ma/j >= temp[i])temp3 = min(ma/j - temp[i], temp3);
      } 
    }
    ans += temp3;
  }
  
  cout<<ans<<endl;
  return 0;
}
  

