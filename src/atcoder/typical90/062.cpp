#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  queue<int> que;
  vector<int> nums(n, -1);
  int num = n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(i);
    g[b].emplace_back(i);
    if (a == i || b == i) {
      que.emplace(i);
      nums[i] = --num;
    }
  }
  while (que.size()) {
    auto u = que.front();
    que.pop();
    for (auto v : g[u]) {
      if (nums[v] != -1) continue;
      que.emplace(v);
      nums[v] = --num;
    }
  }
  if (num > 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[nums[i]] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
