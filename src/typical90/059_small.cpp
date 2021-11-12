#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace std;
using namespace atcoder;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  assert(n <= 2000 && m <= 2000);
  vector<vector<int>> edges(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    edges[u].emplace_back(v);
  }
  for (int qi = 0; qi < q; qi++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    vector<bool> seen(n, false);
    auto dfs = [&](auto dfs, int u) -> bool {
      seen[u] = true;
      if (u == v) return true;
      for (auto v : edges[u]) {
        if (seen[v]) continue;
        auto ret = dfs(dfs, v);
        if (ret) return true;
      }
      return false;
    };
    auto ans = dfs(dfs, u) ? "Yes" : "No";
    cout << ans << '\n';
  }
  return 0;
}
