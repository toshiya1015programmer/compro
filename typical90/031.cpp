#include <bits/stdc++.h>
using namespace std;

int dp[51][1501];

int dfs(int w, int b) {
  if (dp[w][b] != -1) {
    return dp[w][b];
  }
  if (w == 0 && b <= 1) {
    return dp[w][b] = 0;
  }
  vector<bool> mex(1501);
  if (w > 0) {
    mex[dfs(w - 1, b + w)] = true;
  }
  for (int i = 1; i <= b / 2; i++) {
    mex[dfs(w, b - i)] = true;
  }
  for (int i = 0; ; i++) {
    if (!mex[i]) {
      return dp[w][b] = i;
    }
  }
}

int main() {
  for (int w = 0; w <= 50; w++) {
    for (int b = 0; b <= 1500; b++) {
      dp[w][b] = -1;
    }
  }
  for (int w = 0; w <= 50; w++) {
    for (int b = 0; b <= 50; b++) {
      dfs(w, b);
    }
  }
  int n;
  cin >> n;
  vector<int> w(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int grundy = 0;
  for (int i = 0; i < n; i++) {
    grundy ^= dp[w[i]][b[i]];
  }
  if (grundy == 0) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
  return 0;
}
