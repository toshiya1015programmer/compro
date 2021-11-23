#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

long long dp[62][2][2];

long long solve(long long r, long long n) {
  if (r == 0) {
    return 0;
  }
  rep(i, 62) rep(j, 2) rep(k, 2) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  int N = 64 - __builtin_clzll(r);
  rep(i, N) {
    auto f = [&](long long x) {
      return (x >> (N - i - 1)) & 1;
    };
    rep(j, 2) rep(k, 2) rep(l, 2) {
      if (j == 0 && f(r) < l) continue;
      int nj = j != 0 || f(r) > l;
      if (k == 0 && (f(n) ^ l) > f(n)) continue;
      int nk = k != 0 || (f(n) ^ l) < f(n);
      dp[i + 1][nj][nk] += dp[i][j][k];
    }
  }
  return dp[N][0][1] + dp[N][1][1];
}

int main() {
  long long n, l, r;
  cin >> n >> l >> r;
  long long ans = solve(r, n) - solve(l - 1, n);
  cout << ans << endl;
  return 0;
}
