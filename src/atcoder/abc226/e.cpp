#include <bits/stdc++.h>
#include <atcoder/dsu>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n, m;
  cin >> n >> m;
  if (n != m) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> cnts(n);
  vector<vector<int>> g(n);
  dsu dsu(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (!dsu.same(u, v)) {
      int pu = dsu.leader(u);
      int pv = dsu.leader(v);
      dsu.merge(u, v);
      cnts[dsu.leader(u)] = cnts[pu] + cnts[pv] + 1;
    } else {
      cnts[dsu.leader(u)] += 1;
    }
  }
  set<int> pars;
  for (int i = 0; i < n; i++) {
    if (dsu.size(i) == 1) {
      cout << 0 << endl;
      return 0;
    }
    if (cnts[dsu.leader(i)] != dsu.size(i)) {
      cout << 0 << endl;
      return 0;
    }
    pars.insert(dsu.leader(i));
  }
  cout << ((mint) 2).pow(pars.size()).val() << endl;
  return 0;
}
