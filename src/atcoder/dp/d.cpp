#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

template <typename T, typename S> ostream& operator<<(ostream &stream, const pair<T, S> &p) {
  stream << "(" << p.first << "," << p.second << ")";
  return stream;
}

template <typename T> istream& operator>>(istream &stream, vector<T> &v) {
  for (auto &x : v) {
    stream >> x;
  }
  return stream;
}

template <typename T> ostream& operator<<(ostream &stream, const vector<T> &v) {
  int n = (int) v.size();
  for (int i = 0; i < n; i++) {
    stream << v[i] << (i == n - 1 ? "" : " ");
  }
  return stream;
}

template <typename T, typename S> ostream& operator<<(ostream &stream, map<T, S> &m) {
  for (auto p : m) {
    stream << "(" << p.first << "," << p.second << ") ";
  }
  return stream;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, W;
  cin >> n >> W;
  vector<int> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];
  vector dp(n + 1, vector<long long>(W + 1, -1001001001));
  dp[0][0] = 0;
  rep(i, n) rep(j, W + 1) {
    if (dp[i][j] == -1001001001) continue;
    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    if (j + w[i] <= W) dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
  }
  long long ans = 0;
  rep(i, W + 1) ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
