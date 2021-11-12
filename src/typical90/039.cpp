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
  long long ans = 0;
  auto dfs = [&](auto dfs, int u, int p) -> int {
    int sum = 1;
    for (auto v : edges[u]) {
      if (v == p) continue;
      sum += dfs(dfs, v, u);
    }
    ans += (long long) sum * (n - sum);
    return sum;
  };
  dfs(dfs, 0, -1);
  cout << ans << endl;
  return 0;
}
