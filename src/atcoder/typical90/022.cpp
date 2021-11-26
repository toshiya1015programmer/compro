#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long x = __gcd(__gcd(a, b), c);
  long long ans = 0;
  ans += a / x - 1;
  ans += b / x - 1;
  ans += c / x - 1;
  cout << ans << endl;
  return 0;
}
