#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint dp[100000][4];

int main() {
  int n;
  cin >> n;
  vector<char> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    dp[i][c[i] == 'a' ? 1 : 2] = 1;
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
    vector<mint> tmp(4);
    for (int i = 0; i < 4; i++) {
      tmp[i] = dp[u][i];
    }
    for (auto v : g[u]) {
      if (v == p) continue;
      dfs(dfs, v, u);
      vector<mint> out(4);
      for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
          if (j == 3) {
            out[i] += tmp[i] * dp[v][j];
          }
          out[i | j] += tmp[i] * dp[v][j];
        }
      }
      tmp = out;
    }
    for (int i = 0; i < 4; i++) {
      dp[u][i] = tmp[i];
    }
  };
  dfs(dfs, 0, -1);
  auto ans = dp[0][3];
  cout << ans.val() << endl;
  return 0;
}
