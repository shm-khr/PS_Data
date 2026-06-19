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
    for(j = temp[i]; j <= ma; j++){
      if(ma%j == 0){
	break;
	} 
    }
    ans += j - temp[i];
  }
  
  cout<<ans<<endl;
  return 0;
}

