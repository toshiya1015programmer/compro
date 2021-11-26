#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  const int B = 500;
  vector<vector<int>> lg(n);
  for (int u = 0; u < n; u++) {
    int c = g[u].size();
    if (c < B) continue;
    for (auto v : g[u]) {
      int d = g[v].size();
      if (d < B) continue;
      lg[u].emplace_back(v);
    }
  }
  vector<int> dir(n, -1);
  vector<int> indir(n, -1);
  vector<int> colors(q);
  for (int qi = 0; qi < q; qi++) {
    int u;
    cin >> u;
    u--;
    int c = g[u].size();
    if (c >= B) {
      int idx = max(dir[u], indir[u]);
      for (auto v : lg[u]) {
        idx = max(idx, dir[v]);
      }
      int col = idx == -1 ? u : colors[idx];
      colors[qi] = col;
      dir[u] = qi;
      for (auto v : lg[u]) {
        indir[v] = qi;
      }
    } else {
      int idx = max(dir[u], indir[u]);
      for (auto v : g[u]) {
        idx = max(idx, dir[v]);
      }
      int col = idx == -1 ? u : colors[idx];
      colors[qi] = col;
      dir[u] = qi;
      for (auto v : g[u]) {
        indir[v] = qi;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int idx = max(dir[i], indir[i]);
    int c = g[i].size();
    if (c >= B) {
      for (auto v : lg[i]) idx = max(idx, dir[v]);
    } else {
      for (auto v : g[i]) idx = max(idx, dir[v]);
    }
    int col = (idx == -1 ? i : colors[idx]) + 1;
    cout << col << (i == n - 1 ? "\n" : " ");
  }
  return 0;
}
