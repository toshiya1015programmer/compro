#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
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
  int groupCount;
  {
    dsu dsu(h * w);
    for (int x = 0; x < h; x++) {
      for (int y = 0; y < w; y++) {
        if (!can[x * w + y]) continue;
        if (x < h - 1 && can[(x + 1) * w + y]) {
          dsu.merge(x * w + y, (x + 1) * w + y);
        }
        if (y < w - 1 && can[x * w + (y + 1)]) {
          dsu.merge(x * w + y, x * w + (y + 1));
        }
      }
    }
    set<int> se;
    for (int x = 0; x < h; x++)
    for (int y = 0; y < w; y++) {
      if (!can[x * w + y]) continue;
      se.insert(dsu.leader(x * w + y));
    }
    groupCount = se.size();
  }
  set<pair<int, int>> splits;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!can[i * w + j]) continue;
      dsu dsu(h * w);
      can[i * w + j] = false;
      for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
          if (!can[x * w + y]) continue;
          if (x < h - 1 && can[(x + 1) * w + y]) {
            dsu.merge(x * w + y, (x + 1) * w + y);
          }
          if (y < w - 1 && can[x * w + (y + 1)]) {
            dsu.merge(x * w + y, x * w + (y + 1));
          }
        }
      }
      set<int> se;
      for (int x = 0; x < h; x++)
      for (int y = 0; y < w; y++) {
        if (!can[x * w + y]) continue;
        se.insert(dsu.leader(x * w + y));
      }
      if ((int) se.size() > groupCount) {
        splits.emplace(i, j);
      }
      can[i * w + j] = true;
    }
  }
  map<int, map<int, int>> cnts;
  int index = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!can[i * w + j]) continue;
      queue<pair<int, int>> que;
      vector<bool> seen(h * w);
      que.emplace(i, j);
      seen[i * w + j] = true;
      while (que.size()) {
        auto [x, y] = que.front();
        que.pop();
        cnts[index][(x + y) % 2] += 1;
        if (splits.count(make_pair(x, y)) > 0) {
          continue;
        }
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
          if (!can[nx * w + ny] || seen[nx * w + ny]) continue;
          que.emplace(nx, ny);
          seen[nx * w + ny] = true;
        }
      }
      index += 1;
    }
  }
  int ans = 0;
  for (auto p : cnts) {
    ans = max(ans, min(p.second[0], p.second[1]) * 2);
  }
  if (ans == 0) ans = -1;
  cout << ans << endl;
  return 0;
}
