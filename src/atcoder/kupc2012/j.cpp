#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  assert(n <= 100);
  vector<long long> w(n);
  vector<long long> sums(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    sums[i + 1] += w[i];
    sums[i + 1] += sums[i];
  }
  vector dp(n + 1, vector<long long>(n + 1, 1001001001001001001ll));
  for (int i = 0; i < n; i++) {
    dp[i][i + 1] = 0;
  }
  for (int range = 2; range <= n; range++) {
    for (int l = 0; l + range <= n; l++) {
      int r = l + range;
      for (int k = l + 1; k + 1 <= r; k++) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + (sums[r] - sums[l]));
      }
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}
