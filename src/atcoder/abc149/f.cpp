#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

/**
 * 【個数の期待値は、事象の個数÷全事象の個数】
 * 
 * 各頂点について期待値を求めると良いが、今回の場合は期待値を求めるよりも、
 * 各頂点の事象の個数を求めた後に全事象で割ったほうがシンプル
 * なぜかというと、今回は「注目している部分木に黒が含まれている確率」を求めたいが、
 * これには「他の部分木はすべて白であって欲しい」という確率が含まれているので、
 * この確率も計算する必要がある
 * 確率ではなく事象の個数にすれば、他の部分木がすべて白の個数は1になり、
 * 注目している部分木に黒が含まれているものの個数だけを数えれば良くなる
 */
int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  vector<int> dps(n);
  auto dfs1 = [&](auto dfs1, int u, int p = -1) -> int {
    int size = 1;
    for (auto v : g[u]) {
      if (v == p) continue;
      size += dfs1(dfs1, v, u);
    }
    return dps[u] = size;
  };
  dfs1(dfs1, 0);
  vector<mint> dp(n);
  auto dfs2 = [&](auto dfs2, int u, int p = -1) -> void {
    int psize = n - 1;
    for (auto v : g[u]) {
      if (v == p) continue;
      dfs2(dfs2, v, u);
      psize -= dps[v];
    }
    mint ret = ((mint) 2).pow(n - 1) - 1;
    for (auto v : g[u]) {
      int sz = v == p ? psize : dps[v];
      ret -= ((mint) 2).pow(sz) - 1;
    }
    dp[u] = ret;
  };
  dfs2(dfs2, 0);
  mint ans = 0;
  for (int u = 0; u < n; u++) {
    ans += dp[u];
  }
  ans /= ((mint) 2).pow(n);
  cout << ans.val() << endl;
  return 0;
}
