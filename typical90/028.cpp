#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> board(1002, vector<int>(1002));
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    board[a][b] += 1;
    board[c][d] += 1;
    board[a][d] -= 1;
    board[c][b] -= 1;
  }
  for (int i = 0; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      board[i][j] += board[i][j - 1];
    }
  }
  for (int j = 0; j <= 1000; j++) {
    for (int i = 1; i <= 1000; i++) {
      board[i][j] += board[i - 1][j];
    }
  }
  vector<int> ans(n + 1);
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      ans[board[i][j]] += 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
