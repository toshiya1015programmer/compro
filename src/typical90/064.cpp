#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<long long> d(n - 1);
  long long ans = 0;
  int prev = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (i > 0) {
      d[i - 1] = a - prev;
      ans += abs(d[i - 1]);
    }
    prev = a;
  }
  for (int i = 0; i < q; i++) {
    int l, r, v;
    cin >> l >> r >> v;
    l--, r--;
    if (l > 0) {
      ans -= abs(d[l - 1]);
      d[l - 1] += v;
      ans += abs(d[l - 1]);
    }
    if (r < n - 1) {
      ans -= abs(d[r]);
      d[r] -= v;
      ans += abs(d[r]);
    }
    cout << ans << '\n';
  }
  return 0;
}
