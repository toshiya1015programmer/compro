#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> l(n, 1001001001), r(n, 1001001001);
  vector<int> lans(n), rans(n);
  for (int i = 0; i < n; i++) {
    int idx = lower_bound(l.begin(), l.end(), a[i]) - l.begin();
    l[idx] = a[i];
    lans[i] = idx + 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    int idx = lower_bound(r.rbegin(), r.rend(), a[i]) - r.rbegin();
    r[n - idx - 1] = a[i];
    rans[i] = idx + 1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, lans[i] + rans[i] - 1);
  }
  cout << ans << endl;
  return 0;
}
