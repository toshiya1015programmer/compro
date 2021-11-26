#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

template <typename T> ostream& operator<<(ostream &stream, const vector<T> &v) {
  int n = (int) v.size();
  for (int i = 0; i < n; i++) {
    stream << v[i] << (i == n - 1 ? "" : " ");
  }
  return stream;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n + 1);
  rep(i, n) {
    int u = i;
    int v = i + 1;
    g[u].emplace_back(v, 1);
    g[v].emplace_back(u, 0);
  }
  rep(i, m) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    g[l].emplace_back(r, r - l - x);
  }
  using P = pair<int, int>;
  priority_queue<P, vector<P>, greater<P>> q;
  q.emplace(0, 0);
  vector<int> dist(n + 1, 1001001001);
  while (q.size()) {
    auto [cost, u] = q.top();
    q.pop();
    if (dist[u] != 1001001001) continue;
    dist[u] = cost;
    for (auto [v, c] : g[u]) {
      if (dist[v] != 1001001001) continue;
      q.emplace(cost + c, v);
    }
  }
  vector<int> ans(n);
  rep(i, n) {
    ans[i] = (dist[i + 1] - dist[i] == 0 ? 1 : 0);
  }
  cout << ans << endl;
  return 0;
}
