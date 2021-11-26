#include <bits/stdc++.h>
using namespace std;

double dp[301][301][301];

int main() {
  int n;
  cin >> n;
  vector<int> c(3);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a--;
    c[a] += 1;
  }
  auto dfs = [&](auto dfs, int i, int j, int k) -> double {
    if (i < 0 || j < 0 || k < 0) return 0;
    if (i == 0 && j == 0 && k == 0) return 0;
    if (dp[i][j][k] != 0) return dp[i][j][k];
    double acc = 1;
    acc += i * dfs(dfs, i - 1, j, k) / n;
    acc += j * dfs(dfs, i + 1, j - 1, k) / n;
    acc += k * dfs(dfs, i, j + 1, k - 1) / n;
    return dp[i][j][k] = acc * n / (i + j + k);
  };
  auto ans = dfs(dfs, c[0], c[1], c[2]);
  cout << fixed << setprecision(20) << ans << endl;
  return 0;
}
