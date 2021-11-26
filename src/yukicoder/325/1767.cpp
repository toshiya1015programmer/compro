#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  long long ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    int bl = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    int br = upper_bound(b.begin(), b.end(), a[i + 1]) - b.begin();
    if (bl == br) {
      continue;
    }
    long long mi = 0;
    mi = max(mi, b[bl] - a[i] - 1);
    mi = max(mi, a[i + 1] - b[br - 1] - 1);
    for (int j = bl; j + 1 < br; j++) {
      mi = max(mi, b[j + 1] - b[j] - 1);
    }
    ans += a[i + 1] - a[i] - 1 - mi;
  }
  {
    auto it = lower_bound(b.begin(), b.end(), a[0]);
    if (it != b.begin()) {
      ans += a[0] - b[0];
    }
  }
  {
    auto it = lower_bound(b.begin(), b.end(), a[n - 1]);
    if (it != b.end()) {
      ans += b[m - 1] - a[n - 1];
    }
  }
  cout << ans << endl;
  return 0;
}
