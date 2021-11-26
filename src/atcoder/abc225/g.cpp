#include <bits/stdc++.h>
#include <atcoder/all>
#define INF 1001001001001ll
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int main() {
  int h, w, c;
  cin >> h >> w >> c;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  vector<pair<int, int>> es;
  rep(i, h - 1) rep(j, w - 1) {
    int u = i * w + j;
    int v = (i + 1) * w + (j + 1);
    if (v < h * w) es.emplace_back(u, v);
  }
  rep(i, h - 1) rep(j, w - 1) {
    int u = i * w + j + 1;
    int v = (i + 1) * w + j;
    if (v < h * w) es.emplace_back(u, v);
  }
  int n = h * w + (int) es.size();
  int s = n;
  int t = s + 1;
  long long acc = 0;
  mf_graph<long long> g(n + 2);
  rep(i, h) rep(j, w) {
    int u = i * w + j;
    g.add_edge(s, u, 1001001001ll - a[i][j] + c * 2);
    g.add_edge(u, t, 1001001001ll);
    acc += 1001001001ll;
  }
  for (int i = 0; i < (int) es.size(); i++) {
    int u = es[i].first;
    int v = es[i].second;
    int tmp = h * w + i;
    acc += c;
    g.add_edge(tmp, t, c);
    g.add_edge(u, tmp, INF);
    g.add_edge(v, tmp, INF);
  }
  auto ans = acc - g.flow(s, t);
  cout << ans << endl;
  return 0;
}
