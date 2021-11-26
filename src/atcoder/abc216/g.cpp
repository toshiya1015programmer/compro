#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

template <typename T> ostream& operator<<(ostream &stream, const vector<T> &v) {
  int n = (int) v.size();
  for (int i = 0; i < n; i++) {
    stream << v[i] << (i == n - 1 ? "" : " ");
  }
  return stream;
}

using S = int;
S op(S a, S b) { return min(a, b); }
S e() { return 1001001001; }
using F = int;
S mapping(F f, S x) { return f == 0 ? x : x + f; }
F composition(F f, F g) { return f == 0 ? g : g + f; }
F id() { return 0; }

int main() {
  int n, m;
  cin >> n >> m;
  lazy_segtree<S, op, e, F, mapping, composition, id> lst(m);
  vector<vector<tuple<int, int, int, int, int>>> events(n + 1);
  rep(i, m) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    events[l].emplace_back(0, i, l, r, x);
    events[r].emplace_back(1, i, l, r, x);
  }
  vector<int> ans;
  rep(i, n) {
    for (auto [t, j, l, r, x] : events[i]) {
      if (t == 0) {
        lst.set(j, r - x);
      }
    }
    int ni = lst.prod(0, m);
    if (i == ni) {
      ans.push_back(1);
      lst.apply(0, m, 1);
    } else {
      ans.push_back(0);
    }
    for (auto [t, j, l, r, x] : events[i + 1]) {
      if (t == 1) {
        lst.set(j, 1001001001);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
