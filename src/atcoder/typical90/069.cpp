#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int main() {
  long long n;
  int k;
  cin >> n >> k;
  mint ans = 1;
  for (int i = 0; i < min(2ll, n); i++) {
    ans *= max(k - i, 0);
  }
  ans *= ((mint) k - 2).pow(max(n - 2, 0ll));
  cout << ans.val() << endl;
  return 0;
}
