#include <atcoder/all>
#include <bits/stdc++.h>
#define popcount __builtin_popcountll
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
using namespace atcoder;
using namespace std;
template <typename T> bool chmax(T &a, const T& b) { if (a < b) { a = b; return true; } return false; }
template <typename T> bool chmin(T &a, const T& b) { if (a > b) { a = b; return true; } return false; }

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
  vector<int> s(n);
  cin >> s;
  sort(s.begin(), s.end());
  int t;
  cin >> t;
  int now = 0;
  int ans = 0;
  while (now < n) {
    int x = s[now];
    // at>=xを満たす最小のa => a>=x/t => a=ceil(x/t)
    int l = (x + t - 1) / t * t;
    int r = lower_bound(s.begin(), s.end(), l) - s.begin();
    ans += 1;
    now = r;
  }
  cout << ans << endl;
  return 0;
}
