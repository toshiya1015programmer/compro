#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<pair<int, int>> edges;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    edges.emplace_back(u, v);
  }
  vector<bool> large(n);
  rep(i, n) {
    long long n = g[i].size();
    large[i] = n * n > m;
  }
  vector<vector<int>> lg(n);
  for (auto e : edges) {
    if (large[e.first] && large[e.second]) {
      lg[e.first].emplace_back(e.second);
      lg[e.second].emplace_back(e.first);
    }
  }
  int q;
  cin >> q;
  vector<int> color(q);
  vector<int> dirid(n, -1);
  vector<int> indir(n, -1);
  rep(qi, q) {
    int x, y;
    cin >> x >> y;
    x--;
    if (large[x]) {
      auto id = -1;
      id = max(id, dirid[x]);
      id = max(id, indir[x]);
      for (auto v : lg[x]) {
        id = max(id, dirid[v]);
      }
      if (id == -1) {
        cout << 1 << '\n';
      } else {
        cout << color[id] << '\n';
      }
      for (auto v : lg[x]) {
        indir[v] = qi;
      }
    } else {
      auto id = -1;
      id = max(id, dirid[x]);
      id = max(id, indir[x]);
      for (auto v : g[x]) {
        id = max(id, dirid[v]);
      }
      if (id == -1) {
        cout << 1 << '\n';
      } else {
        cout << color[id] << '\n';
      }
      for (auto v : g[x]) {
        indir[v] = qi;
      }
    }
    dirid[x] = qi;
    color[qi] = y;
  }
  return 0;
}
