#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using vm = vector<mint>;
using vvm = vector<vm>;

int main() {
  long long N, B, K;
  cin >> N >> B >> K;
  vector<int> power10(61);
  power10[0] = 10 % B;
  for (int i = 1; i <= 60; i++) {
    power10[i] = power10[i - 1] * power10[i - 1] % B;
  }
  vector<int> c(K);
  for (int i = 0; i < K; i++) {
    cin >> c[i];
  }
  vvm dp(61, vm(B));
  for (int i = 0; i < K; i++) {
    dp[0][c[i] % B] += 1;
  }
  for (int i = 0; i < 60; i++) {
    for (int j = 0; j < B; j++) {
      for (int k = 0; k < B; k++) {
        int t = (power10[i] * j + k) % B;
        dp[i + 1][t] += dp[i][j] * dp[i][k];
      }
    }
  }
  vector<mint> ans(B);
  ans[0] = 1;
  for (int i = 0; i <= 60; i++) {
    if (N & (1ll << i)) {
      auto tmp = ans;
      ans = vector<mint>(B);
      for (int j = 0; j < B; j++) {
        for (int k = 0; k < B; k++) {
          int t = (power10[i] * j + k) % B;
          ans[t] += tmp[j] * dp[i][k];
        }
      }
    }
  }
  cout << ans[0].val() << endl;
  return 0;
}
