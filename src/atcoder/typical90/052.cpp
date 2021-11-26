#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int main() {
  int n;
  cin >> n;
  mint ans = 1;
  for (int i = 0; i < n; i++) {
    mint acc = 0;
    for (int j = 0; j < 6; j++) {
      int a;
      cin >> a;
      acc += a;
    }
    ans *= acc;
  }
  cout << ans.val() << endl;
  return 0;
}
