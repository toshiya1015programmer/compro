#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<vector<int>> mygroups(n);
  vector<vector<int>> vs(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int r;
      cin >> r;
      r--;
      vs[i].emplace_back(r);
      mygroups[r].emplace_back(i);
    }
  }
  vector<int> ans(n, -1);
  queue<int> que;
  que.emplace(0);
  ans[0] = 0;
  while (que.size()) {
    int u = que.front();
    que.pop();
    for (auto g : mygroups[u]) {
      for (int i = vs[g].size() - 1; i >= 0; i--) {
        int v = vs[g][i];
        if (ans[v] == -1) {
          ans[v] = ans[u] + 1;
          que.emplace(v);
        }
        vs[g].pop_back();
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
