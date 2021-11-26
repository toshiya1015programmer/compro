#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  vector<vector<int>> dp(n + 1, vector<int>(s + 1));
  dp[0][0] = 1;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    for (int j = 0; j <= s; j++) {
      if (dp[i][j] == 0) continue;
      if (j + a[i] <= s) dp[i + 1][j + a[i]] = 1;
      if (j + b[i] <= s) dp[i + 1][j + b[i]] = 1;
    }
  }
  if (dp[n][s] == 0) {
    cout << "Impossible" << endl;
    return 0;
  }
  string ans;
  int now = s;
  for (int i = n - 1; i >= 0; i--) {
    if (now - a[i] >= 0 && dp[i][now - a[i]]) {
      ans += 'A';
      now -= a[i];
    } else {
      ans += 'B';
      now -= b[i];
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
