#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

using S = long long;
S op(S a, S b) { return max(a, b); }
S e() { return 0ll; }

int main() {
  int H, W, h1, w1, h2, w2;
  cin >> H >> W >> h1 >> w1 >> h2 >> w2;
  vector<vector<int>> a(H, vector<int>(W));
  rep(i, H) rep(j, W) cin >> a[i][j];
  vector<vector<long long>> acc(H + 1, vector<long long>(W + 1));
  rep(i, H) rep(j, W) acc[i+1][j+1] = a[i][j];
  rep(i, H + 1) rep(j, W) acc[i][j + 1] += acc[i][j];
  rep(j, W + 1) rep(i, H) acc[i + 1][j] += acc[i][j];
  h2 = min(h1, h2);
  w2 = min(w1, w2);
  vector<segtree<S, op, e>> st(H, segtree<S, op, e>(W));
  for (int i = h2; i <= H; i++) {
    for (int j = w2; j <= W; j++) {
      int pi = i - h2;
      int pj = j - w2;
      long long x = acc[i][j] - acc[pi][j] - acc[i][pj] + acc[pi][pj];
      st[i - 1].set(j - 1, x);
    }
  }
  long long ans = 0;
  for (int j = w1; j <= W; j++) {
    int diff = j - w1;
    int l = w2 - 1 + diff;
    int r = w1 + diff;
    multiset<long long, greater<long long>> mp;
    for (int i = 0; i <= h1 - 2; i++) {
      mp.insert(st[i].prod(l, r));
    }
    for (int i = h1; i <= H; i++) {
      mp.insert(st[i - 1].prod(l, r));
      int pi = i - h1;
      int pj = j - w1;
      long long sum = acc[i][j] - acc[pi][j] - acc[i][pj] + acc[pi][pj];
      ans = max(ans, sum - *mp.begin());
      mp.erase(mp.find(st[i - (h1 - h2 + 1)].prod(l, r)));
    }
  }
  cout << ans << endl;
  return 0;
}
