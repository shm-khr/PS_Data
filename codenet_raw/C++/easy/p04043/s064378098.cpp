#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N,L;
string S[101];

int main()
{
  cin >> N, L;
  for (int i = 0; i < N; ++i) cin >> S[i];
  sort(S,S+N);
  for (int i = 0; i < N; ++i) cout << S[i];
  return 0;
}