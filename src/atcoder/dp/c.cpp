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

int dp[100001][4];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(3));
  cin >> v;
  rep(i, n + 1) rep(j, 4) dp[i][j] = -1001001001;
  dp[0][0] = 0;
  rep(i, n) rep(j, 4) rep(k, 3) {
    if (dp[i][j] == -1001001001) continue;
    if (j > 0 && j == k + 1) continue;
    dp[i + 1][k + 1] = max(dp[i + 1][k + 1], dp[i][j] + v[i][k]);
  }
  int ans = 0;
  rep(i, 4) ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
