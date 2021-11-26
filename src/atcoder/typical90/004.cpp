#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> hsum(h), wsum(w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      hsum[i] += a[i][j];
      wsum[j] += a[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int ans = hsum[i] + wsum[j] - a[i][j];
      cout << ans << " ";
    }
    cout << '\n';
  }
  return 0;
}
