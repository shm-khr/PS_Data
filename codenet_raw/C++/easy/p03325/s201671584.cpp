#include <iostream>
#include <numeric>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <functional>

#define repd(i,a,b); for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define ll long long int
 
 
using namespace std;
int main() {
  int n,ans; cin >> n;
  int a[n];
  rep(i,n){
    cin >> a[i];
      rep(j,32){
        if(a[i]%2 == 0){
          cnt++;
          a[i] = a[i]/2;
        } else {
          break;
        }
      }
  }
 cout << ans;
 return 0;
}