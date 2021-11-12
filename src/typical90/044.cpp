#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int now = 0;
  for (int i = 0; i < q; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 2) {
      now = (now + n - 1) % n;
      continue;
    }
    if (t == 1) {
      x--, y--;
      x = (x + now) % n;
      y = (y + now) % n;
      swap(a[x], a[y]);
      continue;
    }
    if (t == 3) {
      x--;
      x = (x + now) % n;
      cout << a[x] << '\n';
    }
  }
  return 0;
}
