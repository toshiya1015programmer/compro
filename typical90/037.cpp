#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;

using S = long long;
S op(S a, S b) { return max(a, b); }
S e() { return -1e18; }
using F = long long;
S mapping(F f, S x) { return f == 0 ? x : max(x, f); }
F composition(F f, F g) { return f == 0 ? g : max(g, f); }
F id() { return 0; }

int main() {
  int w, n;
  cin >> w >> n;
  lazy_segtree<S, op, e, F, mapping, composition, id> dp(w + 1);
  dp.set(0, 0);
  for (int i = 0; i < n; i++) {
    int l, r, v;
    cin >> l >> r >> v;
    for (int j = w - l; j >= 0; j--) {
      auto val = dp.get(j);
      if (val >= 0) {
        int mi = j + l;
        int ma = min(w + 1, j + r + 1);
        dp.apply(mi, ma, val + v);
      }
    }
  }
  long long ans = dp.get(w);
  if (ans < 0) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
