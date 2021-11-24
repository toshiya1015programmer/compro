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
  $0
  return 0;
}
