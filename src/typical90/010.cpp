#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> sums(2, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    int c, p;
    cin >> c >> p;
    c--;
    sums[c][i + 1] += p;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      sums[i][j + 1] += sums[i][j];      
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    cout << sums[0][r] - sums[0][l] << " " << sums[1][r] - sums[1][l] << '\n';
  }
  return 0;
}
