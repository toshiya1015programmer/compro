#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  vector<bool> can(h * w, true);
  for (int i = 0; i < h; i++) {
    cin >> c[i];
    for (int j = 0; j < w; j++) {
      if (c[i][j] == '#') can[i * w + j] = false;
    }
  }
  while (true) {
    int delcnt = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (!can[i * w + j]) continue;
        int c = 0;
        for (int k = 0; k < 4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
          if (can[nx * w + ny]) c += 1;
        }
        if (c <= 1) {
          delcnt += 1;
          can[i * w + j] = false;
        }
      }
    }
    if (delcnt == 0) break;
  }
  int ans = 0;
  for (int i = 0; i < h * w; i++) {
    ans += can[i];
  }
  if (ans % 2 == 1) ans--;
  if (ans == 0) ans = -1;
  cout << ans << endl;
  return 0;
}
