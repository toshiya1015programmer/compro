#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  scc_graph g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g.add_edge(a, b);
  }
  long long ans = 0;
  for (auto v : g.scc()) {
    long long x = v.size();
    ans += x * (x - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
