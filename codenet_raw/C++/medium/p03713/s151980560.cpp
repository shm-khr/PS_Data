#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
using namespace std;
int main(){
  int H,W;
  cin >> H >> W;
  if(H % 3 == 0 || W % 3 == 0){
    cout << "0" << endl;
  }else if(W % 2 == 0){
    int M = 0;
    double m = (double)H / 3;
    if(m - H/3 >= 0.5){
      M = H/3 + 1;
    }else{
      M = H/3;
    }
//  cout << M << endl;
    cout << abs(H - 3 * M) * W /2 << endl;
  }else if(H % 2 == 0){
      int M = 0;
      double m = (double)W / 3;
      if(m - W/3 >= 0.5){
        M = W/3 + 1;
      }else{
        M = W/3;
      }
  //  cout << M << endl;
      cout << abs(W - 3 * M) * H /2 << endl;
    }else if(W % 2 == 1 && H % 2 == 1){
      int M = 0;
      double m = (double)H / 3;
      if(m - H/3 >= 0.5){
        M = H/3 + 1;
      }else{
        M = H/3;
      }
      int N = (W - 1)/2;
      int S[3]= {(H-M)*N, (H-M)*(W-N),M*W};
      int ans1 = max(max(abs(S[0]-S[1]),abs(S[1]-S[2])),abs(S[2]-S[0]));
      //cout << ans1 << endl;
      swap(H,W);
       M = 0;
       m = (double)H / 3;
      if(m - H/3 >= 0.5){
        M = H/3 + 1;
      }else{
        M = H/3;
      }
       N = (W - 1)/2;
       int S2[3]= {(H-M)*N, (H-M)*(W-N),M*W};
       int ans2 = max(max(abs(S2[0]-S2[1]),abs(S2[1]-S2[2])),abs(S2[2]-S2[0]));
      int ans = min(ans1,ans2);
      ans = min(ans,W);
      ans = min(ans,H);
      cout << ans << endl;



        // int N = 0;
        // double n = (double)W / 3;
        // if(n - W/3 >= 0.5){
        //   N = W/3 + 1;
        // }else{
        //   N = W/3;
        // }
        // int S[4]= {M*N, M*(W-N),(H-M)*(W-N),N*(H-M)};
        // int ans[4];
        // for(int i = 0; i < 4; i++){
        //   ans[i] = 0;
        // }
        // int Ans = 10000000l;
        // for(int i = 0; i < 4; i++){
        //   int s1 = S[i]+S[(i+1)%4];
        //   int s2 = S[(i+2)%4];
        //   int s3 = S[(i+3)%4];
        //   ans[i] = max(max(abs(s1-s2),abs(s2-s3)),abs(s3-s1));
        // }
        // for(int i = 0; i < 4; i++){
        //   Ans = min(ans[i],Ans);
        // }
        // cout << Ans << endl;
    }

  return 0;
}
