#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

template<typename T>
struct SparseTable {
  vector<vector<T>> st;
  vector<int> lookup;

  SparseTable(const vector<T> &v) {
    int b = 0;
    while((1 << b) <= (int) v.size()) ++b;
    st.assign(b, vector<T>(1 << b));
    for(int i = 0; i < (int) v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < (int) lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return max(st[b][l], st[b][r - (1 << b)]);
  }
};

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
  vector<vector<long long>> tv(H, vector<long long>(W));
  for (int i = h2; i <= H; i++) {
    for (int j = w2; j <= W; j++) {
      int pi = i - h2;
      int pj = j - w2;
      long long x = acc[i][j] - acc[pi][j] - acc[i][pj] + acc[pi][pj];
      tv[i - 1][j - 1] = x;
    }
  }
  vector<SparseTable<long long>> st;
  for (int i = 0; i < H; i++) {
    st.push_back(SparseTable<long long>(tv[i]));
  }
  long long ans = 0;
  for (int j = w1; j <= W; j++) {
    int diff = j - w1;
    int l = w2 - 1 + diff;
    int r = w1 + diff;
    multiset<long long, greater<long long>> mp;
    for (int i = 0; i <= h1 - 2; i++) {
      mp.insert(st[i].rmq(l, r));
    }
    for (int i = h1; i <= H; i++) {
      mp.insert(st[i - 1].rmq(l, r));
      int pi = i - h1;
      int pj = j - w1;
      long long sum = acc[i][j] - acc[pi][j] - acc[i][pj] + acc[pi][pj];
      ans = max(ans, sum - *mp.begin());
      mp.erase(mp.find(st[i - (h1 - h2 + 1)].rmq(l, r)));
    }
  }
  cout << ans << endl;
  return 0;
}
