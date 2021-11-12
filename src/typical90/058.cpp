#include <bits/stdc++.h>
using namespace std;

int ketawa(int x) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

int main() {
  int max = 100000;
  vector<vector<int>> dp(61, vector<int>(max));
  for (int i = 0; i < max; i++) {
    int ne = (i + ketawa(i)) % max;
    dp[0][i] = ne;
  }
  for (int i = 1; i <= 60; i++) {
    for (int j = 0; j < max; j++) {
      dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
  }
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 60; i >= 0; i--) {
    if (k & (1ll << i)) {
      n = dp[i][n];
    }
  }
  cout << n << endl;
  return 0;
}
