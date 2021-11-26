#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int nx = x[x.size() / 2];
  int ny = y[y.size() / 2];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(nx - x[i]);
    ans += abs(ny - y[i]);
  }
  cout << ans << endl;
  return 0;
}
