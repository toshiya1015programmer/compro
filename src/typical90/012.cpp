#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> board(h, vector<int>(w));
  dsu dsu(h * w);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    if (x == 1) {
      int r, c;
      cin >> r >> c;
      r--, c--;
      board[r][c] = 1;
      for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
        if (board[nr][nc]) {
          dsu.merge(nr * w + nc, r * w + c);
        }
      }
    } else {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      ra--, ca--, rb--, cb--;
      if (board[ra][ca] && board[rb][cb] && dsu.same(ra * w + ca, rb * w + cb)) {
        cout << "Yes" << '\n';
      } else {
        cout << "No" << '\n';
      }
    }
  }
  return 0;
}
