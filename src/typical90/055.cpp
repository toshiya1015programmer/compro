#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long p, q;
  cin >> n >> p >> q;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  auto dfs = [&](auto dfs, int x, int mi = -1, long long acc = 1) -> void {
    if (x == 5) {
      if (acc == q) ans += 1;
      return;
    }
    for (int i = mi + 1; i < n; i++) {
      long long ac = acc * a[i] % p;
      dfs(dfs, x + 1, i, ac);
    }
  };
  dfs(dfs, 0);
  cout << ans << endl;
  return 0;
}
