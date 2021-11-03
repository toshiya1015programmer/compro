#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> xy(n);
  long long minx = 1e18, maxx = -1e18, miny = 1e18, maxy = -1e18;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    xy[i] = pair<int, int>(x - y, x + y);
    minx = min(minx, (long long) x - y);
    maxx = max(maxx, (long long) x - y);
    miny = min(miny, (long long) x + y);
    maxy = max(maxy, (long long) x + y);
  }
  for (int i = 0; i < q; i++) {
    int j;
    cin >> j;
    j -= 1;
    long long ans = 0;
    ans = max(ans, abs(xy[j].first - minx));
    ans = max(ans, abs(xy[j].first - maxx));
    ans = max(ans, abs(xy[j].second - miny));
    ans = max(ans, abs(xy[j].second - maxy));
    cout << ans << '\n';
  }
  return 0;
}
