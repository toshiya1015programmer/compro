#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

long long calc(int x) {
  for (int i = 1; ; i++) {
    int ni = i + 1;
    if (ni * (ni + 1) / 2 > x) {
      return i;
    }
  }
}

int main() {
  int n;
  cin >> n;
  auto asdf = [&](int n) -> vector<int> {
    vector<int> hist;
    auto dfs = [&](auto dfs, int rest) -> void {
      if (rest == 0) return;
      auto c = calc(rest);
      hist.push_back(c);
      dfs(dfs, rest - c * (c + 1) / 2);
    };
    dfs(dfs, n);
    return hist;
  };
  auto v = asdf(n);
  int len = v.size();
  int m = 0;
  set<int> mods;
  mods.insert(0);
  int now = 0;
  string ans;
  for (int i = len - 1; i >= 0; i--) {
    ans = string(v[i], '7') + ans;
    m += v[i];
    int p = pow_mod(10, m, 7);
    if (i > 0) {
      for (int k = 1; k <= 9; k++) {
        int nk = (p * k + now) % 7;
        if (mods.count(nk)) continue;
        mods.insert(nk);
        char c = '0' + k;
        ans = c + ans;
        now = nk;
        break;
      }
    }
    m += 1;
  }
  cout << ans << endl;
  string s = ans;
  int _n = n;
  n = s.size();
  {
    vector<int> sums(n + 1);
    int acc = 1;
    for (int i = n - 1; i >= 0; i--) {
      sums[i] = ((s[i] - '0') * acc + sums[i + 1]) % 7;
      acc = acc * 10 % 7;
    }
    // rep(i, n) cerr << sums[i] << (i == n - 1 ? '\n' : ' ');
    map<int, int> cnt;
    rep(i, n + 1) cnt[sums[i]] += 1;
    long long ans = 0;
    for (auto p : cnt) {
      long long x = p.second;
      ans += x * (x - 1) / 2;
    }
    cerr << ans << endl;
    assert(_n == ans);
  }
  return 0;
}
