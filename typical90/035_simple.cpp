#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  int q;
  cin >> q;
  assert(n <= 5000 && q <= 5000);
  set<int> se;
  auto dfs = [&](auto dfs, int u, int p) -> int {
    int cnt = 0;
    for (auto v : g[u]) {
      if (v == p) continue;
      cnt += dfs(dfs, v, u);
    }
    if (cnt == 0 && se.count(u) == 0) {
      return 0;
    } else {
      return cnt + 1;
    }
  };
  for (int i = 0; i < q; i++) {
    int k, start;
    cin >> k;
    se.clear();
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      v--;
      se.insert(v);
      if (j == 0) start = v;
    }
    int ans = dfs(dfs, start, -1) - 1;
    cout << ans << endl;
  }
  return 0;
}
