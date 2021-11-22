#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
#define chmin(x, y) x = min(x, y)
using namespace std;
using namespace atcoder;

int main() {
  int n, k;
  cin >> n >> k;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  sort(s.begin(), s.end(), [&](string s, string t) {
    // return s + t <= t + s; は RE
    return s + t < t + s;
  });
  // 辞書順最小の文字列を作るときは後ろからDP
  reverse(s.begin(), s.end());
  vector dp(n + 1, vector<string>(k + 2, "~"));
  dp[0][0] = "";
  rep(i, n) rep(j, k + 1) {
    if (dp[i][j] == "~") continue;
    chmin(dp[i + 1][j], dp[i][j]);
    chmin(dp[i + 1][j + 1], s[i] + dp[i][j]);
  }
  cout << dp[n][k] << endl;
  return 0;
}
