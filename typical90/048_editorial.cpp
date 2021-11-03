#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  vector<int> c;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    c.emplace_back(b[i]);
    c.emplace_back(a[i] - b[i]);
  }
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    ans += c[i];
  }
  cout << ans << endl;
  return 0;
}
