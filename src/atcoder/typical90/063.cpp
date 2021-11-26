#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector p(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> p[i][j];
    }
  }
  int ans = 0;
  for (int s = 0; s < (1 << h); s++) {
    map<int, int> cnt;
    for (int j = 0; j < w; j++) {
      int prev = -1;
      for (int i = 0; i < h; i++) {
        if (s & (1 << i)) {
          if (prev == -1) prev = p[i][j];
          else if (prev != p[i][j]) {
            prev = -1;
            break;
          }
        }
      }
      if (prev != -1) {
        cnt[prev] += 1;
      }
    }
    if (cnt.size() == 0) {
      continue;
    }
    int ma = 0;
    for (auto p : cnt) {
      ma = max(ma, p.second);
    }
    int ret = ma * __builtin_popcount(s);
    if (ret > ans) {
      ans = ret;
    }
  }
  cout << ans << endl;
  return 0;
}
