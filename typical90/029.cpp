#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }
using F = int;
F mapping(F f, S x) { return f == 0 ? x : f; }
F composition(F f, F g) { return f == 0 ? g : f; }
F id() { return 0; }

int main() {
  int w, n;
  cin >> w >> n;
  lazy_segtree<S, op, e, F, mapping, composition, id> lst(w + 1);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    int ans = lst.prod(l, r);
    cout << ans + 1 << "\n";
    lst.apply(l, r, ans + 1);
  }
  return 0;
}
