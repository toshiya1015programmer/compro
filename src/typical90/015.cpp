#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int main() {
  vector<mint> fac(100001);
  fac[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    fac[i] = fac[i - 1] * i;
  }
  int n;
  cin >> n;
  for (int k = 1; k <= n; k++) {
    mint ans = 0;
    for (int i = 1; i <= (n + k - 1) / k; i++) {
      int x = n - (k - 1) * (i - 1);
      ans += fac[x] / fac[i] / fac[x - i];
    }
    cout << ans.val() << '\n';
  }
  return 0;
}
