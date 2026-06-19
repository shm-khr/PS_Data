#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

const int mmod = 1000000007;

int prv[1<<18], nxt[1<<18];

int main()
{
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  prv[0] = 1;

  int sum = x+y+z;

  for (int iter=0; iter<n; iter++) {
    for (int i=0; i<(1<<sum); i++)
      nxt[i] = 0;

    for (int i=0; i<(1<<sum); i++) {
      for (int add=1; add<=10; add++) {
        int bit = 0;
        if (i&(1<<(sum-1))) bit = 1<<(sum-1);
        if (add <= 7)
        for (int j=0; j<sum; j++) {
          if (j > 0 && !(i&(1<<(j-1)))) continue;
          if (j == sum) {
            bit |= 1<<(j-1);
            continue;
          }
          int k = j + add;
          if (j < x && k > x) continue;
          if (j < x+y && k > x+y) continue;
          if (k > x+y+z) break;
          bit |= 1<<(k-1);
        }
        nxt[bit] = (nxt[bit] + prv[i]);
        if (nxt[bit] >= mmod) nxt[bit] -= mmod;
      }
    }
    
    for (int i=0; i<(1<<sum); i++)
      prv[i] = nxt[i];
  }

  int ret = 0;
  for (int i=0; i<(1<<sum); i++)
    if (i&(1<<(sum-1))) ret = (ret + prv[i]) % mmod;

  printf("%d\n", ret);
}
