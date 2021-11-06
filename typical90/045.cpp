#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<long long> memo(1 << n, -1);
  auto dist = [&](int s) -> long long {
    if (memo[s] != -1) {
      return memo[s];
    }
    long long ret = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((s & (1 << i)) && (s & (1 << j))) {
          long long xd = x[i] - x[j];
          long long yd = y[i] - y[j];
          ret = max(ret, xd * xd + yd * yd);
        }
      }
    }
    return memo[s] = ret;
  };
  vector<vector<long long>> dp(k + 1, vector<long long>(1 << n, 1e18));
  dp[0][0] = 0;
  for (int i = 0; i < k; i++) {
    for (int s = 0; s < (1 << n); s++) {
      // bit 集合の集合 s を包含する集合 t の列挙
      for (int t = s; t < (1 << n); t = (t + 1) | s) {
        int u = t - s;
        dp[i + 1][t] = min(dp[i + 1][t], max(dp[i][s], dist(u)));
      }
    }
  }
  auto ans = dp[k][(1 << n) - 1];
  cout << ans << endl;
  return 0;
}
