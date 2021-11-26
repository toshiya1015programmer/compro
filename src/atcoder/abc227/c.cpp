#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long a = 1; a <= 10000; a++) {
    long long na = n / a;
    for (long long b = a; b * b <= na; b++) {
      long long nab = na / b;
      ans += max(0ll, nab - b + 1);
    }
  }
  cout << ans << endl;
  return 0;
};
