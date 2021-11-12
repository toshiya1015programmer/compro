#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace std;
using namespace atcoder;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> edges;

  auto vertices = [&]() {
    scc_graph g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g.add_edge(u, v);
      edges.emplace_back(u, v);
    }
    return g.scc();
  }();
  
  vector<int> to(n);
  int n_ = vertices.size();
  for (int i = 0; i < n_; i++) {
    for (auto u : vertices[i]) {
      to[u] = i;
    }
  }
  vector<vector<int>> g(n_);
  for (auto [u, v] : edges) {
    int tu = to[u], tv = to[v];
    g[tu].emplace_back(tv);
  }
  vector<vector<tuple<int, int, int>>> in(n_);
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    int tu = to[u], tv = to[v];
    in[tu].emplace_back(u, tv, i);
  }

  // BIT_SIZE定数の値を書き換えると、メモリ使用量が大きく変化する
  // 具体的には、値が大きいほどメモリ使用量が小さくなる
  // ・BIT_SIZE=32  1,260,104 KB
  // ・BIT_SIZE=36  1,124,364 KB
  // ・BIT_SIZE=40  1,016,032 KB
  // ・BIT_SIZE=64    649,664 KB
  const int BIT_SIZE = 64;

  vector<vector<bitset<BIT_SIZE>>> dp(n_);
  auto to_xy = [&](int a) {
    int x = a / BIT_SIZE;
    int y = a % BIT_SIZE;
    return make_pair(x, y);
  };
  vector<string> ans(q);
  for (int tu = n_ - 1; tu >= 0; tu--) {
    int usize = n_ - tu;
    dp[tu] = vector<bitset<BIT_SIZE>>((usize + BIT_SIZE - 1) / BIT_SIZE);
    auto [x, y] = to_xy(usize - 1);
    dp[tu][x].set(y, true);

    for (auto tv : g[tu]) {
      int vsize = n_ - tv;
      for (int i = 0; i < min(usize, vsize); i += BIT_SIZE) {
        auto [x, _] = to_xy(i);
        dp[tu][x] |= dp[tv][x];
      }
    }

    for (auto [u, tv, i] : in[tu]) {
      auto [x, y] = to_xy(n_ - tv - 1);
      if (x < (int) dp[tu].size() && dp[tu][x].test(y)) {
        ans[i] = "Yes";
      } else {
        ans[i] = "No";
      }
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
