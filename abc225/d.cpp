#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> pr(n, -1), ne(n, -1);
  for (int qi = 0; qi < q; qi++) {
    int k;
    cin >> k;
    if (k == 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      ne[u] = v;
      pr[v] = u;
    } else if (k == 2) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      ne[u] = -1;
      pr[v] = -1;
    } else {
      int u;
      cin >> u;
      u--;
      while (pr[u] != -1) u = pr[u];
      vector<int> ans;
      while (u != -1) {
        ans.push_back(u);
        u = ne[u];
      }
      cout << ans.size() << " ";
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << (i == ans.size() - 1 ? "\n" : " ");
      }
    }
  }
  return 0;
};
