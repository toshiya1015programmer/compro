#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint dp[100001][8];

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 8; j++) {
      dp[i + 1][j] += dp[i][j];
    }
    string t = "atcoder";
    if (t.find(s[i]) == string::npos) {
      continue;
    }
    int x = t.find(s[i]);
    dp[i + 1][x + 1] += dp[i][x];
  }
  cout << dp[n][7].val() << endl;
  return 0;
}
