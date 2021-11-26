#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

// 偏角ソート
int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    vector<double> vec;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      auto s = atan2(y[j] - y[i], x[j] - x[i]) * 180 / M_PI;
      vec.emplace_back(s);
    }
    for (int i = 0; i < n - 1; i++) {
      vec.emplace_back(vec[i] + 360);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n - 1; i++) {
      auto it = lower_bound(vec.begin(), vec.end(), vec[i] + 180);
      if (it != vec.end()) {
        auto v = *it - vec[i];
        if (v >= 180) v = 360 - v;
        ans = max(ans, v);
      }
      if (it != vec.begin()) {
        auto v = *prev(it) - vec[i];
        if (v >= 180) v = 360 - v;
        ans = max(ans, v);
      }
    }
  }
  cout << setprecision(16) << ans << endl;
  return 0;
}
