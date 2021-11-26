#include <bits/stdc++.h>
using namespace std;

template <int mod>
struct ModInt {
  int x;
  ModInt(): x(0) {}
  ModInt(long long a) { x = a % mod; if (x < 0) x += mod; }
  ModInt &operator+=(ModInt that) { x = (x + that.x) % mod; return *this; }
  ModInt &operator-=(ModInt that) { x = (x + mod - that.x) % mod; return *this; }
  ModInt &operator*=(ModInt that) { x = (long long) x * that.x % mod; return *this; }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
  ModInt inverse() {
    int a = x, b = mod, u = 1, v = 0;
    while (b) { int t = a / b; a -= t * b; u -= t * v; swap(a, b); swap(u, v); }
    return ModInt(u);
  }
  #define op(o, p) ModInt operator o(ModInt that) { return ModInt(*this) p that; }
    op(+, +=) op(-, -=) op(*, *=) op(/, /=)
  #undef op
  friend ostream& operator<<(ostream &os, ModInt m) { return os << m.x; }
};

using mint = ModInt<998244353>;

mint dp[200000][3][3];

int main() {
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    s += t;
  }
  auto f = [&](char c) {
    switch (c) {
      case '.': return 0;
      case 'd': return 1;
      case 'k': return 2;
    }
  };
  n *= 16;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    bool isodd = i % 2 == 0;
    int ni = i + 1;
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (s[i] == '.') {
          if (!isodd) {
            if (j == 0 && k == 0) {
              dp[ni][f('.')][j] += dp[i][j][k];
            } else if (j != 0) {
              dp[ni][f('.')][j] += dp[i][j][k];
            }
          } else {
            if (j == 0) {
              dp[ni][f('.')][j] += dp[i][j][k];
            }
          }
        }
        if (s[i] == 'd' || (s[i] == '.' && (i == n - 1 || s[i + 1] == '.' || s[i + 1] == 'k'))) {
          if (isodd) {
            dp[ni][f('d')][j] += dp[i][j][k];
          } else {
            if (j != 0) {
              dp[ni][f('d')][j] += dp[i][j][k];
            }
          }
        }
        if (s[i] == 'k' || (s[i] == '.' && (i == n - 1 || s[i + 1] == '.' || s[i + 1] == 'd'))) {
          if (isodd) {
            dp[ni][f('k')][j] += dp[i][j][k];
          } else {
            if (j != 0) {
              dp[ni][f('k')][j] += dp[i][j][k];
            }
          }
        }
      }
    }
  }
  mint ans = 0;
  for (int j = 0; j < 3; j++) {
    for (int k = 0; k < 3; k++) {
      ans += dp[n][j][k];
    }
  }
  cout << ans << endl;
  return 0;
}
