#include <bits/stdc++.h>
#include <atcoder/modint>
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
      mint cnt = 1;
      int rest = n;
      for (auto v : ord) {
        cnt *= comb(rest, v) * facts(v - 1);
        rest -= v;
      }
      for (auto p : mp) {
        cnt /= facts(p.second);
      }
      ans += cnt * ((mint) l).pow(k);
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
