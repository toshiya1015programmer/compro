#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  for (int i = 0; i < h; i++) {
    cin >> c[i];
  }
  vector<int> can;
  vector<int> mp(1 << 25);
  for (int i = 0; i < (1 << (w + 1)); i++) {
    int cnt = 0;
    for (int j = 0; j < w; j++) {
      if ((i & (1 << j)) != 0 && (i & (1 << (j + 1))) != 0) {
        cnt += 1;
      }
    }
    if (cnt <= 1) {
      mp[i] = can.size();
      can.emplace_back(i);
    }
  }
  vector<vector<mint>> dp(2, vector<mint>(can.size()));
  dp[0][0] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int pre = (i * w + j) % 2;
      int nex = (pre + 1) % 2;
      dp[nex] = vector<mint>(can.size());
      int now = i * w + j;
      for (int _k = 0; _k < can.size(); _k++) {
        int k = can[_k];
        int s = (k << 1) & ((1 << (w + 1)) - 1);
        dp[nex][mp[s]] += dp[pre][_k];
        if (c[i][j] == '#') {
          continue;
        }
        if (j > 0 && now - w - 1 >= 0) {
          if (k & (1 << (w))) continue;
        }
        if (now - w >= 0) {
          if (k & (1 << (w - 1))) continue;
        }
        if (j + 1 < w && now - w + 1 >= 0) {
          if (k & (1 << (w - 2))) continue;
        }
        if (j > 0 && now - 1 >= 0) {
          if (k & 1) continue;
        }
        dp[nex][mp[s | 1]] += dp[pre][_k];
      }
    }
  }
  mint ans = 0;
  for (auto v : dp[(h * w) % 2]) {
    ans += v;
  }
  cout << ans.val() << endl;
  return 0;
}
