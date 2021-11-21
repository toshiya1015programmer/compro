#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
  long long n, k, m;
  cin >> n >> k >> m;
  if (m % 998244353 == 0) {
    cout << 0 << endl;
  } else {
    long long x = pow_mod(k, n, 998244352) + 998244352;
    cout << ((mint) m).pow(x).val() << endl;
  }
  return 0;
}
