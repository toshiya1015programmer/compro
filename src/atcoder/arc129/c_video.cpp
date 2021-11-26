#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> sums(1501);
  for (int i = 1; i <= 1500; i++) {
    sums[i] = i * (i + 1) / 2;
  }
  vector<int> dp(1000001, 1001001001);
  dp[0] = 0;
  for (int j = 1; j < (int) sums.size(); j++) {
    for (int i = 0; i <= 1000000; i++) {
      if (dp[i] == 1001001001) continue;
      if (i + sums[j] <= 1000000) {
        dp[i + sums[j]] = min(dp[i + sums[j]], dp[i] + 1); 
      }
    }
  }
  int ans = 0;
  rep(i, 1000001) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
