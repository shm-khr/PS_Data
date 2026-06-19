#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Item {
  ll v, w, m;
  Item(){}
  explicit Item(ll v, ll w, ll m):v(v), w(w), m(m){}
  bool operator < (const Item& item) const {
    return v*item.w < item.v*w;
  }
};

const ll MAX_N = 100;

ll N, W;

int main() {
  cin >> N >> W;
  vector<Item> items;
  for(ll i = 0; i < N; ++i) {
    int v, w, m;
    cin >> v >> w >> m;
    items.emplace_back(v, w, m);
  }
  sort(items.rbegin(), items.rend());

  ll ans = 0;
  for(Item item : items) {
    ll use = min(W/item.w, item.m);
    ans += use*item.v;
    W -= use*item.w;
  }
  cout << ans << endl;

  return 0;
}

