#include <atcoder/all>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace atcoder;
using namespace std;

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
  int n;
  cin >> n;
  vector<int> h(n);
  cin >> h;
  vector<int> dp(n, 1001001001);
  dp[0] = 0;
  rep(i, n) {
    int n1 = i + 1;
    int n2 = i + 2;
    if (n1 < n) dp[n1] = min(dp[n1], dp[i] + abs(h[i] - h[n1]));
    if (n2 < n) dp[n2] = min(dp[n2], dp[i] + abs(h[i] - h[n2]));
  }
  cout << dp[n - 1] << endl;
  return 0;
}
