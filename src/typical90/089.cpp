#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int main() {
  int n;
  long long K;
  cin >> n >> K;
  vector<int> a(n);
  vector<pair<int, int>> za;
  rep(i, n) {
    cin >> a[i];
    za.emplace_back(a[i], i);
  };
  sort(za.begin(), za.end());
  fenwick_tree<mint> dp(n + 1);
  dp.add(0, (mint) 1);
  fenwick_tree<int> st(n);
  long long acc = 0;
  int r = 0;
  rep(i, n) {
    {
      auto p = make_pair(a[i], i);
      int in = lower_bound(za.begin(), za.end(), p) - za.begin();
      acc += st.sum(in, n);
      st.add(in, 1);
    }
    while (acc > K) {
      auto p = make_pair(a[r], r);
      int in = lower_bound(za.begin(), za.end(), p) - za.begin();
      acc -= st.sum(0, in);
      st.add(in, -1);
      r += 1;
    }
    dp.add(i + 1, dp.sum(r, i + 1));
  }
  auto ans = dp.sum(n, n + 1);
  cout << ans.val() << endl; 
  return 0;
}
