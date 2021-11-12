#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint dp[100010][10];

int main() {
  int k;
  cin >> k;
  if (k % 9 != 0) {
    cout << 0 << endl;
    return 0;
  }
  dp[0][0] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 10; j++) {
      if (j > 0) {
        dp[i + 1][1] += dp[i][j];
      }
      if (j < 9) {
        dp[i + 1][j + 1] += dp[i][j];
      }
    }
  }
  mint ans = 0;
  for (int j = 0; j < 10; j++) {
    ans += dp[k][j];
  }
  cout << ans.val() << endl;
  return 0;
}
