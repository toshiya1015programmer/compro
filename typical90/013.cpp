#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<P>> edges(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    edges[a].emplace_back(b, c);
    edges[b].emplace_back(a, c);
  }
  vector<vector<int>> dist(2, vector<int>(n, 1001001001));
  auto bfs = [&](int idx, int s) {
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0, s);
    while (q.size()) {
      int cost, u;
      tie(cost, u) = q.top();
      q.pop();
      if (dist[idx][u] != 1001001001) {
        continue;
      }
      dist[idx][u] = cost;
      for (auto p : edges[u]) {
        int v, c;
        tie(v, c) = p;
        if (dist[idx][v] != 1001001001) {
          continue;
        }
        q.emplace(cost + c, v);
      }
    }
  };
  bfs(0, 0);
  bfs(1, n - 1);
  for (int k = 0; k < n; k++) {
    int ans = dist[0][k] + dist[1][k];
    cout << ans << '\n';
  }
  return 0;
}
