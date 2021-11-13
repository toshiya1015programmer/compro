#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, a;
  cin >> n >> k >> a;
  a--;
  int ans = (k + a - 1) % n + 1;
  cout << ans << endl;
  return 0;
};
