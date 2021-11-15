#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % 10 != 0) {
    cout << "No" << endl;
    return 0;
  }
  sum /= 10;
  for (int i = 0; i < n; i++) {
    a.push_back(a[i]);
  }
  long long su = 0;
  int l = 0, r = 0;
  while (l < n) {
    while (r < 2*n && su + a[r] <= sum) {
      su += a[r++];
    }
    if (su == sum) {
      cout << "Yes" << endl;
      return 0;
    }
    su -= a[l++];
  }
  cout << "No" << endl;
  return 0;
}
