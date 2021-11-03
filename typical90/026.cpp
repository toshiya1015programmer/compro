#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> edges(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    edges[u].emplace_back(v);
    edges[v].emplace_back(u);
  }
  vector<vector<int>> col(2);
  auto dfs = [&](auto dfs, int u, int p, int c = 0) -> void {
    col[c].push_back(u + 1);
    for (auto v : edges[u]) {
      if (v == p) continue;
      dfs(dfs, v, u, 1 - c);
    }
  };
  dfs(dfs, 0, -1);
  if (col[0].size() >= n / 2) {
    for (int i = 0; i < n / 2; i++) {
      cout << col[0][i] << " ";
    }
    cout << endl;
  } else {
    for (int i = 0; i < n / 2; i++) {
      cout << col[1][i] << " ";
    }
    cout << endl;
  }
  return 0;
}
