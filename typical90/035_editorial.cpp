#include <bits/stdc++.h>
using namespace std;

struct LCA {
  int n;
  vector<vector<int>> g;
  vector<vector<int>> par;
  vector<int> dep;
  LCA(int n): n(n) {
    g = vector<vector<int>>(n);
    par = vector<vector<int>>(30, vector<int>(n + 1, n));
    dep = vector<int>(n + 1);
  }
  void add_edge(int u, int v) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  void init() {
    dfs(0);
    for (int i = 1; i < 30; i++) {
      for (int u = 0; u < n; u++) {
        par[i][u] = par[i - 1][par[i - 1][u]];
      }
    }
  }
  void dfs(int u, int p = -1, int d = 0) {
    dep[u] = d;
    par[0][u] = p == -1 ? n : p;
    for (auto v : g[u]) {
      if (v != p) dfs(v, u, d + 1);
    }
  }
  int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 29; i >= 0; i--) {
      if (dep[u] - (1 << i) >= dep[v]) {
        u = par[i][u];
      }
    }
    if (u == v) return u;
    for (int i = 29; i >= 0; i--) {
      if (par[i][u] != par[i][v]) {
        u = par[i][u], v = par[i][v];
      }
    }
    return par[0][u];
  }
  int dist(int u, int v) {
    return dep[u] + dep[v] - dep[lca(u, v)] * 2;
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  LCA lca(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
    lca.add_edge(a, b);
  }
  lca.init();
  vector<int> ords(n);
  int t = 0;
  auto dfs = [&](auto dfs, int u, int p = -1) -> void {
    ords[u] = t++;
    for (auto v : g[u]) {
      if (v == p) continue;
      dfs(dfs, v, u);
    }
  };
  dfs(dfs, 0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    vector<int> c(k);
    for (int j = 0; j < k; j++) {
      cin >> c[j];
      c[j] -= 1;
    }
    sort(c.begin(), c.end(), [&](int u, int v) {
      return ords[u] < ords[v];
    });
    int ans = 0;
    for (int j = 0; j < k; j++) {
      int u = c[j], v = c[(j + 1) % k];
      ans += lca.dist(u, v);
    }
    ans /= 2;
    cout << ans << '\n';
  }
  return 0;
}
