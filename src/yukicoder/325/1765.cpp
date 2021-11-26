#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  reverse(a.begin(), a.end());
  int status = -1;
  long long ans = 0;
  int acc = 0;
  for (int i = 0; i < n; i++) {
    if (status == -1) {
      if (a[i] == 1) {
        status = 0;
        acc = i == 0 ? 0 : 1;
        ans += acc;
      } else {
        status = 1;
        acc = i == 0 ? 0 : 1;
      }
    } else if (status == 0) {
      if (a[i] == 0) {
        status = 1;
        acc += 1;
      } else {
        status = 0;
        acc = 1;
        ans += acc;
      }
    } else if (status == 1) {
      if (a[i] == 1) {
        status = 0;
        acc += 1;
        ans += acc;
      } else {
        status = 1;
        acc = 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
