#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> ts(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> ts[i] >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      v--;
      g[i].emplace_back(v);
    }
  }
  vector<bool> seen(n);
  queue<int> que;
  que.emplace(n - 1);
  seen[n - 1] = true;
  while (que.size()) {
    int u;
    tie(u) = que.front(); que.pop();
    for (auto v : g[u]) {
      if (seen[v]) continue;
      seen[v] = true;
      que.emplace(v);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (seen[i]) ans += ts[i];
  }
  cout << ans << endl;
  return 0;
}
