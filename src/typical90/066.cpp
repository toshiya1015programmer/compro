#include <bits/stdc++.h>
using namespace std;

int main() {
  long double ans = 0;
  int n;
  cin >> n;
  vector<int> L(n), R(n);
  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = L[j]; k <= R[j]; k++) {
        auto x = (long double) min(max(0, R[i] - k), (R[i] - L[i] + 1)) / (R[i] - L[i] + 1);
        auto acc = x / (R[j] - L[j] + 1);
        ans += acc;
      }
    }
  }
  cout << setprecision(16) << ans << endl;
  return 0;
}
