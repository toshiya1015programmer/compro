#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
#define chmin(x, y) x = min(x, y)
using namespace std;
using namespace atcoder;

template <typename T> ostream& operator<<(ostream &stream, const vector<T> &v) {
  int n = (int) v.size();
  for (int i = 0; i < n; i++) {
    stream << v[i] << (i == n - 1 ? "" : " ");
  }
  return stream;
}

vector<int> memo;

string greedy(int n, int k, vector<string> s) {
  vector<int> o(n, -1);
  rep(i, k) o[i] = i;
  sort(o.begin(), o.end());
  string ans = string(n, 'z');
  do {
    vector<int> t(k);
    rep(i, n) if (~o[i]) t[o[i]] = i;
    string acc;
    rep(i, k) acc += s[t[i]];
    if (ans > acc) {
      ans = acc;
      memo = o;
    }
  } while (next_permutation(o.begin(), o.end()));
  return ans;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  vector<vector<int>> g(n);
  vector<int> in(n);
  // 選ぶ順序は貪欲に決められるらしい（未証明）
  // 2つの文字列 s[i],s[j] の S=s[i]+s[j] と T=s[j]+s[i] を辞書順比較し、
  // S<=T であれば i->j に、S>T であれば j->i に有向辺を張る
  // こうして構築したグラフはDAGになっている（未証明）

  // 「貪欲に選ぶ方法がないと解ける問題の形になりそうにない」という予感から生まれた未証明の貪欲
  // この感覚は果たして正しいのかどうか
  rep(j, n) rep(i, j) {
    string _s = s[i] + s[j];
    string _t = s[j] + s[i];
    if (_s > _t) {
      g[j].push_back(i);
      in[i] += 1;
    } else {
      g[i].push_back(j);
      in[j] += 1;
    }
  }
  vector<int> hi;
  rep(i, n) if (!in[i]) hi.push_back(i);
  for (int i = 0; i < (int) hi.size(); i++) {
    int u = hi[i];
    for (auto v : g[u]) {
      if (!--in[v]) hi.push_back(v);
    }
  }
  assert(n == (int) hi.size());
  vector<string> ss(n);
  rep(i, n) ss[i] = s[hi[i]];
  vector<vector<vector<string>>> dp(n + 1, vector<vector<string>>(k + 1, vector<string>(2501, "~")));
  dp[0][0][0] = "";
  // 文字数が同じであれば、単純にその時点での辞書順最小の文字列を選ぶのが最適
  // 文字数が異なると、辞書順最小だった文字列が最小でなくなることがある
  // よって、「文字数」の情報もDPに持つ必要がある
  // 最悪ケースでは間に合わなさそう
  rep(i, n) rep(j, k + 1) rep(l, 2501) {
    if (dp[i][j][l] == "~") continue;
    chmin(dp[i + 1][j][l], dp[i][j][l]);
    int nl = l + (int) ss[i].size();
    if (j + 1 <= k && nl <= 2500) {
      chmin(dp[i + 1][j + 1][nl], dp[i][j][l] + ss[i]);
    }
  }
  string ans = "~";
  rep(l, 2501) {
    chmin(ans, dp[n][k][l]);
  }
  cout << ans << endl;
  // cerr << memo << endl;
  // cerr << hi << endl;
  // cerr << ss << endl;
  // cerr << endl;
  // rep(i, k + 1) cerr << dp[n][i] << endl;
  return 0;
}
// naavnaavnanvaanv
// naavnaavnanvaanva
