#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> data;

int l[1000000];
int n;

bool valid(int k) {
  vector<data> v;
  for(int i = 0; i < n; i++) {
    if(i == 0) {
      v.push_back({{1, l[i]}, 1});
      continue;
    }
    while(true) {
      if(v.empty()) return false;
      data curr = v[v.size()-1];
      if(curr.first.first > l[i]) {
        v.pop_back();
      }
      else if(l[i] > curr.first.second) {
        v.push_back({{curr.first.second+1, l[i]}, 1});
        break;
      }
      else {
        // [curr.first, curr.second]
        // l[i] is >= curr.first, <= curr.second
        v.pop_back();
        int currD = curr.second;
        if(currD == k) continue;
        if(l[i]-1 >= curr.first.first) v.push_back({{curr.first.first, l[i]-1}, currD});
        v.push_back({{l[i], l[i]}, currD+1});
        break;
      }
    }
    /*
    printf("AFTER %d\n", i);
    for(auto x: v) {
      printf("%d %d %d\n", x.first.first, x.first.second, x.second);
    }
    */
  }
  return true;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  int lhs = 1;
  int rhs = n;
  while(lhs < rhs) {
    int mid = (lhs+rhs)/2;
    if(valid(mid)) rhs = mid;
    else lhs = mid+1;
  }
  cout << lhs << endl;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
