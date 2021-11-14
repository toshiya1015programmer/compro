#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int h, w, sx, sy;
vector<string> c;
vector<vector<bool>> seen;

int dfs(int x, int y) {
  seen[x][y] = true;
  int ma = -1;
  for (int k = 0; k < 4; k++) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
    if (nx == sx && ny == sy) {
      ma = 1;
      continue;
    }
    if (seen[nx][ny] || c[nx][ny] == '#') continue;
    auto ret = dfs(nx, ny);
    if (ret != -1) {
      ma = max(ma, ret + 1);
    }
  }
  seen[x][y] = false;
  return ma;
}

int main() {
  cin >> h >> w;
  c = vector<string>(h);
  seen = vector<vector<bool>>(h, vector<bool>(w));
  for (int i = 0; i < h; i++) {
    cin >> c[i];
  }
  int ans = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (c[i][j] == '#') continue;
      int ret = dfs(sx = i, sy = j);
      ans = max(ans, ret);
    }
  }
  if (ans <= 2) ans = -1;
  cout << ans << endl;
  return 0;
}
