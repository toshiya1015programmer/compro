#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  vector<long long> abc(3);
  cin >> n;
  for (int i = 0; i < 3; i++) {
    cin >> abc[i];
  }
  long long ans = 1e18;
  sort(abc.begin(), abc.end());
  for (int i = 0; i <= 9999; i++) {
    for (int j = 0; j <= 9999; j++) {
      long long rest = n - abc[1] * i - abc[2] * j;
      if (rest < 0) {
        break;
      }
      if (rest % abc[0] == 0) {
        long long v = i + j + (rest / abc[0]);
        ans = min(ans, v);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
