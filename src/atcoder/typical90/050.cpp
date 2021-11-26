#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint dp[100001];

int main() {
  int n, l;
  cin >> n >> l;
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    dp[i + 1] += dp[i];
    if (i + l <= n) dp[i + l] += dp[i];
  }
  cout << dp[n].val() << endl;
  return 0;
}
