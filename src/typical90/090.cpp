#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using vvm = vector<vector<mint>>;
using vpii = vector<pair<int, int>>;

template <typename T, typename S> ostream& operator<<(ostream &stream, const pair<T, S> &p) {
  stream << "(" << p.first << "," << p.second << ")";
  return stream;
}

template <typename T> istream& operator>>(istream &stream, const vector<T> &v) {
  for (auto &x : v) {
    stream >> x;
  }
  return stream;
}

template <typename T> ostream& operator<<(ostream &stream, const vector<T> &v) {
  int n = (int) v.size();
  for (int i = 0; i < n; i++) {
    stream << v[i] << (i == n - 1 ? "" : " ");
  }
  return stream;
}

template <typename T, typename S> ostream& operator<<(ostream &stream, map<T, S> &m) {
  for (auto p : m) {
    stream << "(" << p.first << "," << p.second << ") ";
  }
  return stream;
}

mint solve2(int n, int K) {
  map<int, int, greater<int>> mp;
  rep(i, K + 1) {
    if (i == 0) mp[1001001001]++;
    else mp[K / i]++;
  }
  vector<pair<int, int>> ranges;
  for (auto p : mp) {
    ranges.push_back(p);
  }
  int rn = ranges.size();
  vector<map<vpii, mint>> dp(n + 1);
  auto init = vpii();
  init.emplace_back(1001001001, 0);
  dp[0][init] = 1;
  rep(i, n) {
    for (auto p : dp[i]) {
      for (int j = 0; j < rn; j++) {
        auto v = p.first;
        int t = lower_bound(v.rbegin(), v.rend(), pair<int, int>(ranges[j].first + 1, 0)) - v.rbegin();
        int r = (int) v.size() - t;
        while (r + 1 < (int) v.size()) {
          v.pop_back();
        }
        bool ok = true;
        rep(k, r) {
          v[k].second += 1;
          if (v[k].first < v[k].second) {
            ok = false;
          }
        }
        if (!ok) {
          continue;
        }
        if (r < (int) v.size()) {
          v.back().first = ranges[j].first;
          v.back().second += 1;
          if (v.back().first < v.back().second) {
            continue;
          }
        } else {
          v.emplace_back(ranges[j].first, 1);
        }
        dp[i + 1][v] += p.second * ranges[j].second;
      }
    }
  }
  mint ans;
  for (auto p : dp[n]) {
    ans += p.second;
  }
  return ans;
}

vvm mat_mul(vvm x, vvm y) {
  vvm res(x.size(), vector<mint>(y[0].size()));
  for (int i = 0; i < (int) x.size(); i++)
  for (int j = 0; j < (int) y[0].size(); j++)
  for (int k = 0; k < (int) x[0].size(); k++) {
    res[i][j] += x[i][k] * y[k][j];
  }
  return res;
}

vvm mat_pow(vvm x, long long n) {
  vvm res(x.size(), vector<mint>(x.size()));
  for (int i = 0; i < (int) x.size(); i++) {
    res[i][i] = 1;
  }
  while (n) {
    if (n & 1) res = mat_mul(res, x);
    n >>= 1, x = mat_mul(x, x);
  }
  return res;
}

mint solve(long long n, int K) {
  mint ans = 0;
  vector<int> a;
  auto dfs = [&](auto dfs, int idx = 0) -> void {
    if (idx == n) {
      bool ok = true;
      rep(r, n + 1) rep(l, r) {
        int mi = 1001001001;
        for (int i = l; i < r; i++) {
          mi = min(mi, a[i]);
        }
        mi *= r - l;
        if (mi > K) ok = false;
      }
      if (ok) {
        // cerr << a << endl;
        ans += 1;
      }
      return;
    }
    rep(i, K + 1) {
      a.push_back(i);
      dfs(dfs, idx + 1);
      a.pop_back();
    }
  };
  dfs(dfs);
  return ans;
}

int main() {
  long long n;
  int K;
  cin >> n >> K;
  if (K == 1) {
    vvm mat(2, vector<mint>(2));
    mat[0][0] = mat[0][1] = mat[1][0] = 1;
    mat = mat_pow(mat, n);
    vvm dp(2, vector<mint>(1));
    dp[0][0] = 1;
    dp = mat_mul(mat, dp);
    cout << (dp[0][0] + dp[1][0]).val() << endl;
    return 0;
  }
  if (n <= 17 && K <= 29) {
    cout << solve2(n, K).val() << endl;
    return 0;
  }
  return 0;
}
