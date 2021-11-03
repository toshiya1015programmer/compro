#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint dp[100010];

int main() {
  int k;
  cin >> k;
  if (k % 9 != 0) {
    cout << 0 << endl;
    return 0;
  }
  dp[0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= 9; j++) {
      if (i - j < 0) continue;
      dp[i] += dp[i - j];
    }
  }
  cout << dp[k].val() << endl;
  return 0;
}
