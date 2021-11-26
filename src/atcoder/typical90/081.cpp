#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int main() {
  int n, K;
  cin >> n >> K;
  vector<int> a(n), b(n);
  vector<vector<int>> dp(5001, vector<int>(5001));
  rep(i, n) {
    cin >> a[i] >> b[i];
    dp[a[i]][b[i]] += 1;
  }
  rep(i, 5001) rep(j, 5000) {
    dp[i][j + 1] += dp[i][j];
  }
  rep(i, 5000) rep(j, 5001) {
    dp[i + 1][j] += dp[i][j];
  }
  int ans = 0;
  reps(i, 5000) reps(j, 5000) {
    int ni = min(5000, i + K);
    int nj = min(5000, j + K);
    ans = max(ans, dp[ni][nj] - dp[ni][j - 1] - dp[i - 1][nj] + dp[i - 1][j - 1]);
  }
  cout << ans << endl;
  return 0;
}
