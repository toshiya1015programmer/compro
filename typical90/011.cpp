#include <bits/stdc++.h>
using namespace std;

long long dp[5001];

int main() {
  int n;
  cin >> n;
  vector<int> d(n), c(n), s(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> c[i] >> s[i];
  }
  vector<int> o(n);
  iota(o.begin(), o.end(), 0);
  sort(o.begin(), o.end(), [&](int i, int j) {
    return d[i] < d[j];
  });
  for (int i = 1; i <= 5000; i++) {
    dp[i] = -1001001001;
  }
  for (int _i = 0; _i < n; _i++) {
    int i = o[_i];
    for (int j = 5000; j >= 0; j--) {
      if (dp[j] == -1001001001) {
        continue;
      }
      if (j + c[i] <= d[i]) {
        dp[j + c[i]] = max(dp[j + c[i]], dp[j] + s[i]);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= 5000; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
