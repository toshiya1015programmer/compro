#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> edges(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges[a].emplace_back(b);
    edges[b].emplace_back(a);
  }
  vector<int> dist(n);
  auto dfs = [&](auto dfs, int u, int p = -1, int d = 0) -> void {
    dist[u] = d;
    for (auto v : edges[u]) {
      if (v == p) continue;
      dfs(dfs, v, u, d + 1);
    }
  };
  dfs(dfs, 0);
  int ma = 0, mai = -1;
  for (int i = 0; i < n; i++) {
    if (ma < dist[i]) {
      ma = dist[i];
      mai = i;
    }
  }
  dfs(dfs, mai);
  ma = 0;
  for (int i = 0; i < n; i++) {
    if (ma < dist[i]) {
      ma = dist[i];
    }
  }
  cout << ma + 1 << endl;
  return 0;
}
