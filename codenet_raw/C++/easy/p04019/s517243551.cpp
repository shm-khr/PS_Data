#include <iostream>
#include <vector>
#include <map>
#include <bitset>

using namespace std;

const int kMax = 1e5 + 17;

bitset < kMax > used;

void Init(vector < long long > &prime) {
  long long index = 0ll;

  for (int pr = 2; pr < kMax; pr ++) {
    if (used[pr]) {
      continue;
    }
    prime[++ index] = pr;

    for (int nr = pr * 2; nr < kMax; nr += pr) {
      used[nr] = true;
    }
  }

  prime[0] = index;
}

int main(int argc, char const *argv[]) {

  vector < long long > prime(kMax);
  Init(prime);

  int n;
  cin >> n;

  map < long long, long long > hash;
  map < long long, long long > comp;
  vector < long long > element(n + 1);

  for (int i = 1; i <= n; i ++) {
    cin >> element[i];
    long long k = element[i];
    
    if (k == 1ll) {
      hash[k] = 1ll;
      comp[k] = 1ll;
      continue;
    }

    long long h = 1ll; 
    long long c = 1ll;
    for (int j = 1; j <= prime[0] and prime[j] * prime[j] <= element[i]; j ++) {
      if (k % prime[j] != 0) {
        continue;
      }

      int elExp = 0;
      while (k % prime[j] == 0) {
        elExp ++;
        k /= prime[j];
      }

      elExp %= 3;
      if (elExp == 0) {
        continue;
      }

      if (elExp == 1) {
        h *= prime[j];
        c *= prime[j] * prime[j];
      }
      else {
        h *= prime[j] * prime[j];  
        c *= prime[j];
      }
    }

    if (k != 1) {
      h *= k;
      c *= k * k;
    }

    hash[element[i]] = h;
    comp[element[i]] = c;
  }

  map < long long, int > frecv;
  for (int i = 1; i <= n; i ++) {
    frecv[hash[element[i]]] ++;
  }

  int to_remove = 0;
  for (auto &x : frecv) {
    if (x.first == 1) {
      to_remove += x.second - 1;
      x.second = 0;
      continue;
    }

    if (x.second == 0) {
      continue;
    }

    int k = x.first;
    int c = frecv[comp[k]];
    if (c == 0) {
      continue;
    }


    if (x.second >= c) {
      to_remove += c;
    }
    else {
      to_remove += x.second;
    }
    x.second = 0;
    frecv[comp[k]] = 0;
  }

  cout << n - to_remove << '\n';
}