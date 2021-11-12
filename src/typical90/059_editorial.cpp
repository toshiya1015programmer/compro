#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<long long> g(m);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[i] = 1ll * v * n + u;
  }
  sort(g.begin(), g.end());
  auto touv = [&](long long x) {
    int v = x / n;
    int u = x % n;
    return make_pair(u, v);
  };
  const int SIZE = 1024;
  vector<int> a(SIZE), b(SIZE);
  for (int i = 0; i < q; i += SIZE) {
    vector<bitset<SIZE>> dp(n);
    for (int qi = 0; qi < min(SIZE, q - i); qi++) {
      cin >> a[qi] >> b[qi];
      a[qi]--, b[qi]--;
      dp[a[qi]].set(qi, true);
    }
    for (int mi = 0; mi < m; mi++) {
      auto [u, v] = touv(g[mi]);
      dp[v] |= dp[u];
    }
    for (int qi = 0; qi < min(SIZE, q - i); qi++) {
      cout << ((dp[b[qi]].test(qi)) ? "Yes" : "No") << '\n';
    }
  }
  return 0;
}
