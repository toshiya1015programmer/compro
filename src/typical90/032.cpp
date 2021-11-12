#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<bool>> can(n, vector<bool>(n, true));
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    can[x][y] = can[y][x] = false;
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  int ans = 1001001001;
  do {
    int sum = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      sum += a[ord[i]][i];
      if (i < n - 1 && !can[ord[i]][ord[i + 1]]) {
        ok = false;
      }
    }
    if (ok) {
      ans = min(ans, sum);
    }
  } while (next_permutation(ord.begin(), ord.end()));
  if (ans == 1001001001) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
