#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int n, P, K;

int cnt(vector<vector<long long>> a, long long x) {
  rep(i, n) rep(j, n) {
    if (a[i][j] == -1) a[i][j] = x;
  }
  rep(k, n) rep(i, n) rep(j, n) {
    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
  }
  int ret = 0;
  rep(j, n) rep(i, j) {
    ret += a[i][j] <= 1ll * P;
  }
  return ret;
}

int main() {
  cin >> n >> P >> K;
  vector<vector<long long>> a(n, vector<long long>(n));
  rep(i, n) rep(j, n) {
    cin >> a[i][j];
  }
  auto ma = [&]() {
    // Xが大きいほどcnt()は小さい値を返す
    // Xの最大値を知りたい→cnt()=Kを満たす最大のXを知りたい
    long long ok = 1001001001001001001ll, ng = 0;
    while (abs(ok - ng) != 1) {
      auto md = (ok + ng) / 2;
      (cnt(a, md) < K ? ok : ng) = md;
    }
    // 半開区間の右なのでokは含まれない
    return ok;
  }();
  auto mi = [&]() {
    // Xが大きいほどcnt()は小さい値を返す
    // Xの最小値を知りたい→cnt()=Kを満たす最小のXを知りたい
    long long ok = 1001001001001001001ll, ng = 0;
    while (abs(ok - ng) != 1) {
      auto md = (ok + ng) / 2;
      (cnt(a, md) <= K ? ok : ng) = md;
    }
    return ok;
  }();
  cerr << mi << " " << ma << endl;
  if (mi == ma) {
    cout << 0 << endl;
    return 0;
  }
  if (ma == 1001001001001001001ll) {
    cout << "Infinity" << endl;
    return 0;
  }
  cout << ma - mi << endl;
  return 0;
}
