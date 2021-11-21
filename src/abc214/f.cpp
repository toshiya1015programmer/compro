#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint dp[200001];

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> pre(n + 2, vector<int>(26, -1));
  for (int i = 0; i <= n; i++) {
    // 配列のコピーを使うと簡単
    pre[i + 1] = pre[i];
    if (i < n) {
      pre[i + 1][s[i] - 'a'] = i;
    }
  }
  vector<mint> dp(n + 2);
  auto dfs = [&](auto dfs, int idx) -> mint {
    if (dp[idx] != 0) return dp[idx];
    mint ret = 1;
    rep(i, 26) {
      int p = pre[idx][i];
      if (p == -1) continue;
      if (p == idx - 1) p = pre[p][i];
      if (p == -1) continue;
      ret += dfs(dfs, p);
    }
    return dp[idx] = ret;
  };
  auto ans = dfs(dfs, n + 1) - 1;
  cout << ans.val() << endl;
  return 0;
}
