#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace boost::multiprecision;

int main() {
  int n, d;
  cin >> n >> d;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] ^= (1ll << d) - 1;
  }
  cpp_int ans = 1ll << d;
  for (int i = 1; i < (1 << n); i++) {
    long long sign = (popcount(i) % 2 == 1) ? -1 : 1;
    long long s = (1ll << d) - 1;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) s &= a[j];
    }
    int c = popcount(s);
    ans += (1ll << c) * sign;
  }
  cout << ans << endl;
  return 0;
}
