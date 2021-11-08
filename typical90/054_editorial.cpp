#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int u, v;
      cin >> u;
      u--;
      v = i + n;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
  }
  vector<int> ans(n + m, -1);
  queue<int> que;
  que.emplace(0);
  ans[0] = 0;
  while (que.size()) {
    int u = que.front();
    que.pop();
    for (auto v : g[u]) {
      if (ans[v] != -1) continue;
      ans[v] = v >= n ? ans[u] : ans[u] + 1;
      que.emplace(v);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
