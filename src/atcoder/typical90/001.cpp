#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l, k;
  cin >> n >> l >> k;
  vector<int> b(n + 1);
  int prev = 0;
  for (int i = 0; i <= n; i++) {
    int a;
    if (i == n) a = l; else cin >> a;
    b[i] = a - prev;
    prev = a;
  }
  int ok = 0, ng = l;
  while (abs(ok - ng) != 1) {
    int m = (ok + ng) >> 1;
    int cnt = 0;
    int acc = 0;
    for (int i = 0; i < n; i++) {
      if (acc + b[i] >= m) {
        acc = 0;
        cnt += 1;
      } else {
        acc += b[i];
      }
    }
    if (acc + b[n] < m) {
      cnt -= 1;
    }
    (cnt >= k ? ok : ng) = m;
  }
  cout << ok << endl;
  return 0;
}
