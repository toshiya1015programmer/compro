#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  int cnt = 0;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      cnt += 1, n /= i;
    }
  }
  if (n != 1) cnt += 1;
  int ans = 0;
  int acc = 1;
  while (acc < cnt) {
    ans += 1;
    acc *= 2;
  }
  cout << ans << endl;
  return 0;
}
