#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  set<pair<int, int>> se;
  rep(i, q) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    se.emplace(a, b);
  }
  vector<vector<vector<int>>> ans(8890);
  vector<int> used;
  vector<int> c(n);
  auto dfs = [&](auto dfs, int s, int sum) -> bool {
    if (s == n) {
      ans[sum].push_back(used);
      if (sum > 0 && (int) ans[sum].size() > 1) {
        rep(i, 2) {
          int n = ans[sum][i].size();
          cout << n << endl;
          rep(j, n) cout << ans[sum][i][j] << (j == n - 1 ? '\n' : ' ');
        }
        return true;
      }
      return false;
    }
    // 使わない
    if (dfs(dfs, s + 1, sum)) {
      return true;
    }
    // 使う
    bool ok = true;
    rep(j, n) {
      if (s == j) continue;
      int ni = s, nj = j;
      if (ni > nj) swap(ni, nj);
      if (c[j] > 0) {
        if (se.count(make_pair(ni, nj)) > 0) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      c[s] += 1;
      used.push_back(s + 1);
      if (dfs(dfs, s + 1, sum + a[s])) {
        return true;
      }
      used.pop_back();
      c[s] -= 1;
    }
    return false;
  };
  dfs(dfs, 0, 0);
  return 0;
}
