#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0};
int dy[] = {0, 1};
long long dp[31][31][62];

int main() {
  int h, w, K;
  cin >> h >> w >> K;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  long long ans = 1e18;
  for (int x = 0; x < h; x++) {
    for (int y = 0; y < w; y++) {
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          for (int k = 0; k <= 60; k++) {
            dp[i][j][k] = 1e18;
          }
        }
      }
      if (a[0][0] >= a[x][y]) {
        dp[0][0][1] = a[0][0];
      }
      if (a[0][0] <= a[x][y]) {
        dp[0][0][0] = 0;
      }
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          for (int k = 0; k <= 60; k++) {
            if (dp[i][j][k] == 1e18) {
              continue;
            }
            for (int l = 0; l < 2; l++) {
              int ni = i + dx[l];
              int nj = j + dy[l];
              if (ni >= h || nj >= w) {
                continue;
              }
              if (a[ni][nj] >= a[x][y]) {
                dp[ni][nj][k + 1] = min(dp[ni][nj][k + 1], dp[i][j][k] + a[ni][nj]);
              }
              if (a[ni][nj] <= a[x][y]) {
                dp[ni][nj][k] = min(dp[ni][nj][k], dp[i][j][k]);
              }
            }
          }
        }
      }
      ans = min(ans, dp[h - 1][w - 1][K]);
    }
  }
  cout << ans << endl;
  return 0;
};
