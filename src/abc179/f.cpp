#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  long long ans = 1ll * (n - 2) * (n - 2);
  vector<map<int, int>> mp(2);
  mp[0][n - 1] = n - 1;
  mp[1][n - 1] = n - 1;
  for (int i = 0; i < q; i++) {
    int t, a;
    cin >> t >> a;
    t--, a--;
    auto it = mp[t].lower_bound(a);
    int y = -1;
    if (it == mp[t].begin()) {
      y = mp[1 - t].begin()->first - 1;
    } else {
      y = (--it)->second;
    }
    ans -= y, mp[t][a] = y;
  }
  cout << ans << endl;
  return 0;
}
