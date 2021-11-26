#include <bits/stdc++.h>
#include <atcoder/maxflow>
using namespace std;
using namespace atcoder;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
  int n, T;
  cin >> n >> T;
  mf_graph<int> g(n * 2 + 2);
  int s = n * 2;
  int t = s + 1;
  vector<pair<int, int>> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    g.add_edge(s, i, 1);
  }
  map<pair<int, int>, int> bindex;
  for (int i = 0; i < n; i++) {
    cin >> b[i].first >> b[i].second;
    bindex[b[i]] = i;
    g.add_edge(n + i, t, 1);
  }
  for (int i = 0; i < n; i++) {
    auto [x, y] = a[i];
    for (int k = 0; k < 8; k++) {
      auto nx = x + 1ll * dx[k] * T;
      auto ny = y + 1ll * dy[k] * T;
      if (bindex.count(make_pair(nx, ny)) > 0) {
        int bi = bindex[make_pair(nx, ny)];
        g.add_edge(i, n + bi, 1);
      }
    }
  }
  auto flow = g.flow(s, t);
  if (flow != n) {
    cout << "No" << endl;
    return 0;
  }
  vector<int> ans(n);
  auto edges = g.edges();
  for (auto e : edges) {
    if (e.flow == 0) continue;
    if (e.from >= 0 && e.from < n && e.to >= n && e.to < 2 * n) {
      auto [ax, ay] = a[e.from];
      auto [bx, by] = b[e.to - n];
      for (int k = 0; k < 8; k++) {
        auto nx = ax + 1ll * dx[k] * T;
        auto ny = ay + 1ll * dy[k] * T;
        if (nx == bx && ny == by) {
          ans[e.from] = k + 1;
          break;
        }
      }
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
