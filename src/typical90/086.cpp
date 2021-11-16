#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> x(q), y(q), z(q);
  vector<long long> w(q);
  rep(i, q) {
    cin >> x[i] >> y[i] >> z[i] >> w[i];
    x[i]--, y[i]--, z[i]--;
  }
  mint ans = 1;
  for (int i = 0; i < 60; i++) {
    int c = 0;
    for (int s = 0; s < (1 << n); s++) {
      bool ok = true;
      for (int j = 0; j < q; j++) {
        int t = ((s >> x[j]) & 1) | ((s >> y[j]) & 1) | ((s >> z[j]) & 1);
        if (t != ((w[j] >> i) & 1)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        c += 1;
      }
    }
    ans *= c;
  }
  cout << ans.val() << endl;
  return 0;
}
