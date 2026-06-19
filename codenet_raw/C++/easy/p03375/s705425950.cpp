#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define DEBUGP(val) cerr << #val << "=" << val << "\n"

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PI;

ll mod;

ll powmod(ll a, ll e) {
  ll sum = 1;
  ll cur = a;
  while (e > 0) {
    if (e % 2) {
      sum = sum * cur % mod;
    }
    cur = cur * cur % mod;
    e /= 2;
  }
  return sum;
}
ll powmod(ll a, ll e, ll mod) {
  ll sum = 1;
  ll cur = a;
  while (e > 0) {
    if (e % 2) {
      sum = sum * cur % mod;
    }
    cur = cur * cur % mod;
    e /= 2;
  }
  return sum;
}

void add(ll &x, ll y) {
  x = (x + y) % mod;
}

const int N = 3010;
ll s2[N][N];
ll comb[N][N];

void init(void) {
  // TODO
  comb[0][0] = 1;
  REP(i, 1, N) {
    REP(j, 0, N) {
      if (j > 0) add(comb[i][j], comb[i - 1][j - 1]);
      add(comb[i][j], comb[i - 1][j]);
    }
  }
  s2[0][0] = 1;
  REP(i, 1, N) {
    REP(j, 0, N) {
      if (j > 0) add(s2[i][j], s2[i - 1][j - 1]);
      add(s2[i][j], s2[i - 1][j] * j);
    }
  }
  if (1) {
    REP(i, 0, 4) {
      REP(j, 0, 4) {
	cerr << " " << s2[i][j];
      }
      cerr << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n >> mod;
  init();
  assert (n <= 100);
  ll tot = 0;
  REP(i, 0, n + 1) {
    ll fac = powmod(2, powmod(2, n - i, mod - 1));
    ll tis = powmod(2, n - i);
    ll ani = 0;
    REP(k, 0, i + 1) {
      REP(j, 0, i + 1) {
	ll tmp = s2[k][j] * powmod(tis, j) % mod;
	tmp = tmp * comb[i][k] % mod;
	tmp = tmp * fac % mod;
	add(ani, tmp);
      }
    }
    ani = ani * comb[n][i] % mod;
    if (i % 2 == 1) ani = (mod - ani) % mod;
    add(tot, ani);
  }
  cout << tot << endl;
}
