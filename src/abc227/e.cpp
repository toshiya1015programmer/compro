#include <bits/stdc++.h>
using namespace std;

long long dp[31][31][31][4651];

int main() {
  string s;
  int K;
  cin >> s >> K;
  K = min(4650, K);
  int n = s.size();
  vector<int> vk, ve, vy;
  vector cnts(3, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    switch (s[i]) {
      case 'K': cnts[0][i + 1] += 1; vk.push_back(i); break;
      case 'E': cnts[1][i + 1] += 1; ve.push_back(i); break;
      case 'Y': cnts[2][i + 1] += 1; vy.push_back(i); break;
    }
    for (int j = 0; j < 3; j++) {
      cnts[j][i + 1] += cnts[j][i];
    }
  }
  int kn = vk.size(), en = ve.size(), yn = vy.size();
  dp[0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int ki = 0; ki <= kn; ki++) {
      for (int ei = 0; ei <= en; ei++) {
        int yi = i - ki - ei;
        if (yi < 0) {
          break;
        }
        for (int c = 0; c <= K; c++) {
          if (ki < kn) {
            int x = vk[ki] + max(0, ei - cnts[1][vk[ki]]) + max(0, yi - cnts[2][vk[ki]]);
            int nc = c + abs(i - x);
            if (nc <= K) {
              dp[i + 1][ki + 1][ei][nc] += dp[i][ki][ei][c];
            }
          }
          if (ei < en) {
            int x = ve[ei] + max(0, ki - cnts[0][ve[ei]]) + max(0, yi - cnts[2][ve[ei]]);
            int nc = c + abs(i - x);
            if (nc <= K) {
              dp[i + 1][ki][ei + 1][nc] += dp[i][ki][ei][c];
            }
          }
          if (yi < yn) {
            int x = vy[yi] + max(0, ki - cnts[0][vy[yi]]) + max(0, ei - cnts[1][vy[yi]]);
            int nc = c + abs(i - x);
            if (nc <= K) {
              dp[i + 1][ki][ei][nc] += dp[i][ki][ei][c];
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int ki = 0; ki <= kn; ki++) {
    for (int ei = 0; ei <= en; ei++) {
      for (int c = 0; c <= K; c++) {
        ans += dp[n][ki][ei][c];
      }
    }
  }
  cout << ans << endl;
  return 0;
};
