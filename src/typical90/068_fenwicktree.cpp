#include <bits/stdc++.h>
#include <atcoder/dsu>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;
  dsu dsu(n);
  fenwick_tree<long long> ft(n - 1);
  vector<bool> used(n);
  for (int i = 0; i < q; i++) {
    long long t, x, y, v;
    cin >> t >> x >> y >> v;
    x--, y--;
    if (t == 0) {
      if (!used[x]) {
        long long sign = (x % 2 == 0) ? 1 : -1;
        ft.add(x, sign * v);
        dsu.merge(x, y);
        used[x] = true;
      }
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
        ans += ft.sum(x, y);
      } else {
        ans -= ft.sum(x, y);
      }
    } else {
      if ((y - 0) % 2 == 0) {
        ans += ft.sum(y, x);
      } else {
        ans -= ft.sum(y, x);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
