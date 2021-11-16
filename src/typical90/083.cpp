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
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  vector<vector<int>> que(n);
  vector<vector<pair<int, int>>> col(n);
  int q;
  cin >> q;
  rep(i, q) {
    int x, y;
    cin >> x >> y;
    x--;
    que[x].emplace_back(i);
    col[x].emplace_back(i, y);
  }
  vector<pair<int, int>> ans(q, pair<int, int>(-1, 1));
  rep(u, n) {
    auto qs = que[u];
    for (auto v : g[u]) {
      for (auto q : que[v]) qs.push_back(q);
    }
    sort(col[u].begin(), col[u].end());
    reverse(col[u].begin(), col[u].end());
    sort(qs.begin(), qs.end());
    for (auto [index, color] : col[u]) {
      int idx = upper_bound(qs.begin(), qs.end(), index) - qs.begin();
      if (idx == (int) qs.size()) continue;
      for (int i = (int) qs.size() - 1; i >= idx; i--) {
        if (ans[qs[i]].first < index) {
          ans[qs[i]] = pair<int, int>(index, color);
        }
        qs.pop_back();
      }
    }
  }
  rep(i, q) cout << ans[i].second << '\n';
  return 0;
}
