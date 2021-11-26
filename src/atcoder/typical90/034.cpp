#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  map<int, int> cnt;
  int r = 0;
  for (int l = 0; l < n; l++) {
    while (r < n) {
      cnt[a[r]] += 1;
      if (cnt.size() > k) {
        break;
      }
      r += 1;
    }
    if (r < n) {
      cnt[a[r]] -= 1;
      if (cnt[a[r]] == 0) cnt.erase(a[r]);
    }
    ans = max(ans, r - l);
    cnt[a[l]] -= 1;
    if (cnt[a[l]] == 0) cnt.erase(a[l]);
  }
  cout << ans << endl;
  return 0;
}
