#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int query(int i) {
  cout << "? " << i + 1 << endl;
  int a;
  cin >> a;
  return a;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l = 0, r = n;
    map<int, int> a;
    while (r - l >= 3) {
      int lr = l + (r - l) / 3 * 1;
      int rl = l + (r - l) / 3 * 2;
      int alr = -1, arl = -1;
      if (a.count(lr) > 0) {
        alr = a[lr];
      } else {
        alr = a[lr] = query(lr);
      }
      if (a.count(rl) > 0) {
        arl = a[rl];
      } else {
        arl = a[rl] = query(rl);
      }
      if (alr > arl) {
        r = rl;
      } else {
        l = lr;
      }
    }
    int ans = 0;
    if (l + 0 < n) {
      if (a.count(l + 0) == 0) a[l + 0] = query(l + 0);
      ans = max(ans, a[l + 0]);
    }
    if (l + 1 < n) {
      if (a.count(l + 1) == 0) a[l + 1] = query(l + 1);
      ans = max(ans, a[l + 1]);
    }
    if (l + 2 < n) {
      if (a.count(l + 2) == 0) a[l + 2] = query(l + 2);
      ans = max(ans, a[l + 2]);
    }
    cout << "! " << ans << endl;
  }
  return 0;
}
