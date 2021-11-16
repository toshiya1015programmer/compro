#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int l = 0, r = 0;
  long long ans = 1ll * n * (n + 1) / 2;
  while (l < n) {
    while (r < n && s[l] == s[r]) r += 1;
    long long x = r - l;
    ans -= x * (x + 1) / 2;
    l = r;
  }
  cout << ans << endl;
  return 0;
}
