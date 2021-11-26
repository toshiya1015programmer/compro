#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint dp[100000][3];

int main() {
  int n;
  cin >> n;
  vector<char> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    dp[i][c[i] == 'a' ? 0 : 1] = 1;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  auto dfs = [&](auto dfs, int u, int p) -> void {
    vector<mint> tmp(3);
    for (int i = 0; i < 3; i++) {
      tmp[i] = dp[u][i];
    }
    for (auto v : g[u]) {
      if (v == p) continue;
      dfs(dfs, v, u);
      vector<mint> out(3);
      out[0] = tmp[0]*dp[v][0] + tmp[0]*dp[v][2];
      out[1] = tmp[1]*dp[v][1] + tmp[1]*dp[v][2];
      out[2] = tmp[0]*dp[v][1] + tmp[0]*dp[v][2] + tmp[1]*dp[v][0] + tmp[1]*dp[v][2] +
               tmp[2]*dp[v][0] + tmp[2]*dp[v][1] + tmp[2]*dp[v][2] * 2;
      tmp = out;
    }
    for (int i = 0; i < 3; i++) {
      dp[u][i] = tmp[i];
    }
  };
  dfs(dfs, 0, -1);
  auto ans = dp[0][2];
  cout << ans.val() << endl;
  return 0;
}
