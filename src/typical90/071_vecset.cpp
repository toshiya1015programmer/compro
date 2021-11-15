#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace std;
using namespace atcoder;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  scc_graph scc(n);
  vector<vector<int>> g(n);
  vector<int> in(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    scc.add_edge(u, v);
    g[u].push_back(v);
    in[v] += 1;
  }
  if ((int) scc.scc().size() != n) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> us;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0) us.push_back(i);
  }
  vector<int> acc;
  vector<vector<int>> ans;
  auto dfs = [&](auto dfs) -> bool {
    if ((int) acc.size() == n) {
      ans.push_back(acc);
      return (int) ans.size() == k;
    }
    int sz = us.size();
    for (int i = 0; i < sz; i++) {
      swap(us[i], us[sz - 1]);
      auto u = us.back();
      us.pop_back();
      acc.push_back(u);
      for (auto v : g[u]) {
        if (!(--in[v])) us.push_back(v);
      }
      auto ret = dfs(dfs);
      if (ret) {
        return true;
      }
      for (auto v : g[u]) {
        if (!(in[v]++)) us.pop_back();
      }
      acc.pop_back();
      us.push_back(u);
      swap(us[i], us[sz - 1]);
    }
    return false;
  };
  if (!dfs(dfs)) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] + 1 << (j == n - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
