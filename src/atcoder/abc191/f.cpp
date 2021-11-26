#include <bits/stdc++.h>
using namespace std;

vector<int> dividers(int x) {
  vector<int> ret;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      ret.push_back(i);
      if (i != x / i) ret.push_back(x / i);
    }
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mi = 1001001001;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mi = min(mi, a[i]);
  }
  map<int, int> gcds;
  for (int i = 0; i < n; i++) {
    auto v = dividers(a[i]);
    for (auto x : v) {
      gcds[x] = __gcd(gcds[x], a[i]);
    }
  }
  int ans = 0;
  for (auto [gcd, val] : gcds) {
    if (gcd == val && gcd <= mi) {
      ans += 1;
    }
  }
  cout << ans << endl;
  return 0;
}
