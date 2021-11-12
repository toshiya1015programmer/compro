#include <bits/stdc++.h>
#define INF 1001001001
using namespace std;
using T = tuple<int, int, int, int>;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dp[1000][1000][4];

int main() {
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      for (int k = 0; k < 4; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  int rs, cs, rt, ct;
  cin >> rs >> cs >> rt >> ct;
  rs--, cs--, rt--, ct--;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  deque<T> dq;
  dq.emplace_front(rs, cs, 0, 0);
  dq.emplace_front(rs, cs, 0, 1);
  dq.emplace_front(rs, cs, 0, 2);
  dq.emplace_front(rs, cs, 0, 3);
  while (dq.size()) {
    int r, c, cost, dir;
    tie(r, c, cost, dir) = dq.front();
    dq.pop_front();
    if (dp[r][c][dir] != INF) {
      continue;
    }
    dp[r][c][dir] = cost;
    for (int i = 0; i < 4; i++) {
      int nr = r + dx[i];
      int nc = c + dy[i];
      if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
      if (s[nr][nc] == '#') continue;
      if (dp[nr][nc][i] != INF) {
        continue;
      }
      if (dir == i) {
        dq.emplace_front(nr, nc, cost, i);
      } else {
        dq.emplace_back(nr, nc, cost + 1, i);
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < 4; i++) {
    ans = min(ans, dp[rt][ct][i]);
  }
  cout << ans << endl;
  return 0;
}
