#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
  vector<mint> pa(51);
  pa[0] = 1;
  for (int i = 1; i <= 50; i++) {
    pa[i] = pa[i - 1] * i;
  }
  auto com = [&](int n, int k) -> mint {
    return pa[n] / pa[k] / pa[n - k];
  };
  int n, k;
  cin >> n >> k;
  vector<int> ord;
  mint ans = 0;
  auto dfs = [&](auto dfs, int index, int len = 1) -> void {
    if (index == n) {
      long long l = 1;
      map<int, int> mp;
      for (auto v : ord) {
        l = l / __gcd(l, (long long) v) * v;
        mp[v] += 1;
      }
      mint ret = 1;
      for (auto p : mp) {
        ret *= pa[p.first - 1].pow(p.second) / (pa[p.first].pow(p.second) * pa[p.second]);
      }
      ret *= pa[n];
      ans += ret * ((mint) l).pow(k);
      return;
    }
    for (int i = len; i <= n - index; i++) {
      ord.push_back(i);
      dfs(dfs, index + i, i);
      ord.pop_back();
    }
  };
  dfs(dfs, 0, 1);
  cout << ans.val() << endl;
  return 0;
}
