#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int b;
    cin >> b;
    auto it = lower_bound(a.begin(), a.end(), b);
    int ans = 1001001001;
    if (it != a.end()) {
      ans = min(ans, *it - b);
    }
    if (it != a.begin()) {
      ans = min(ans, b - *prev(it));
    }
    cout << ans << '\n';
  }
  return 0;
}
