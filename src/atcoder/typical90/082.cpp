#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint cnt(long long x) {
  mint ret = 0;
  long long acc = 1;
  for (int i = 1; i <= 18; i++) {
    long long mi = acc;
    long long ma = min(acc * 10 - 1, x);
    if (ma < mi) break;
    mint c = (mint) mi * (ma - mi + 1) + (mint) (ma - mi) * (ma - mi + 1) / 2;
    ret += c * i;
    acc *= 10;
  }
  if (x == 1000000000000000000ll) {
    ret += (mint) 19 * 1000000000000000000ll;
  }
  return ret;
}

int main() {
  long long l, r;
  cin >> l >> r;
  auto ans = cnt(r) - cnt(l - 1);
  cout << ans.val() << endl;
  return 0;
}
