#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010


bool solve(){
  int r, n;
  int maxh[50] = {};
  
  scanf("%d%d", &r, &n);

  if(r == 0) return false;
  
  for(int i=0;i<n;i++){
    int l, r, h;
    scanf("%d%d%d", &l, &r, &h);

    for(int j=l+20;j<r+20;j++) maxh[j] = max(maxh[j], h);
  }

  double ans = INF;
  
  for(int i=20-r;i<20+r;i++){
    int x = (i<20) + i - 20;

    ans = min(ans, maxh[i] + r - sqrt(r*r-x*x));
  }

  printf("%.5lf\n", ans);

  return 1;
}

int main(){
  while(solve());
  
  return 0;
}

