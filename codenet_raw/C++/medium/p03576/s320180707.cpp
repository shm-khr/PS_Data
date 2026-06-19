#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
const ll INF = 1e+18;

int main()
{
  int n, k;
  cin >> n >> k;

  int x[50], y[50];
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }

  sort(x, x+n);
  sort(y, y+n);

  ll ans = 1LL*(x[n-1] - x[0])*(y[n-1] - y[0]);
  for(int l = 0; l < n; l++){
    for(int r = l+1; r < n; r++){
      for(int b = 0; b < n; b++){
        for(int t = b+1; t < n; t++){
          int num = 0;
          for(int i = 0; i < n; i++){
            if(x[l] <= x[i] && x[i] <= x[r] && y[b] <= y[i] && y[i] <= y[t]){
              num++;
            }
          }
          if(num >= k) ans = min(ans, 1LL*(x[r] - x[l])*(y[t]-y[b]));
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}