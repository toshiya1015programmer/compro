#include <bits/stdc++.h>
#include <atcoder/dsu>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;

using S = long long;
S op(S a, S b) { return a + b; }
S e() { return 0; }

int main() {
  int n, q;
  cin >> n >> q;
  dsu dsu(n);
  segtree<S, op, e> st(n - 1);
  for (int i = 0; i < q; i++) {
    long long t, x, y, v;
    cin >> t >> x >> y >> v;
    x--, y--;
    if (t == 0) {
      long long sign = (x % 2 == 0) ? 1 : -1;
      st.set(x, sign * v);
      dsu.merge(x, y);
      continue;
    }
    if (!dsu.same(x, y)) {
      cout << "Ambiguous" << '\n';
      continue;
    }
    long long ans = 0;
    if (x % 2 == y % 2) {
      ans += v;
    } else {
      ans -= v;
    }
    if (x < y) {
      if ((y - 1) % 2 == 0) {
        ans += st.prod(x, y);
      } else {
        ans -= st.prod(x, y);
      }
    } else {
      if ((y - 0) % 2 == 0) {
        ans += st.prod(y, x);
      } else {
        ans -= st.prod(y, x);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
