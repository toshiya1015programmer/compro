#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/convolution>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

struct modfact {
  int n;
  vector<mint> v;
  modfact(): n(2), v({ 1, 1 }) {}
  mint operator()(int i) {
    while (n <= i) {
      v.emplace_back(v[n - 1] * n);
      n += 1;
    }
    return v[i];
  }
} facts;

struct modfactinv {
  int n;
  vector<mint> v;
  modfactinv(): n(2), v({ 1, 1 }) {}
  mint operator()(int i) {
    while (n <= i) {
      v.emplace_back(v[n - 1] * ((mint) n).inv());
      n += 1;
    }
    return v[i];
  }
} ifacts;

mint comb(int a, int b) {
  if (a < b || a < 0 || b < 0) {
    return 0;
  }
  return facts(a) * ifacts(b) * ifacts(a - b);
}

int main() {
  int r, g, b, k;
  int x, y, z;
  cin >> r >> g >> b >> k >> x >> y >> z;
  int rc = k - y;
  int gc = k - z;
  int bc = k - x;
  vector<mint> gs(g + 1), bs(b + 1);
  for (int i = 0; i <= g; i++) {
    if (i >= gc) gs[i] = comb(g, i);
  }
  for (int i = 0; i <= b; i++) {
    if (i >= bc) bs[i] = comb(b, i);
  }
  auto gbs = convolution(gs, bs);
  mint ans = 0;
  for (int i = rc; i <= min(r, k); i++) {
    int rest = k - i;
    ans += comb(r, i) * (rest < (int) gbs.size() ? gbs[rest] : 0);
  }
  cout << ans.val() << endl;
  return 0;
}
