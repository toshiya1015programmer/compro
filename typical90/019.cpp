#include <bits/stdc++.h>
using namespace std;

int dp[401][401];

int main() {
  for (int i = 0; i <= 400; i++) {
    for (int j = 0; j <= 400; j++) {
      if (i == j) continue;
      dp[i][j] = 1001001001;
    }
  }
  int n;
  cin >> n;
  vector<int> a(n * 2);
  for (int i = 0; i < n * 2; i++) {
    cin >> a[i];
  }
  for (int range = 2; range <= 2 * n; range += 2) {
    for (int l = 0; l + range <= 2 * n; l += 1) {
      int r = l + range;
      for (int k = l + 1; k + 1 <= r; k += 1) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r]);
      }
      dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + abs(a[l] - a[r - 1]));
    }
  }
  cout << dp[0][2 * n] << endl;
  return 0;
}
