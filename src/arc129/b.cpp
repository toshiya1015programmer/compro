#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int minr = 1001001001;
  int maxl = -1001001001;
  rep(i, n) {
    int l, r;
    cin >> l >> r;
    minr = min(minr, r);
    maxl = max(maxl, l);
    int ans = (max(0, maxl - minr) + 1) / 2;
    cout << ans << '\n';
  }
  return 0;
}
