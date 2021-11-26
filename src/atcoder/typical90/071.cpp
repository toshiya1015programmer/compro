#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;

using S = int;
S op(S a, S b) { return min(a, b); }
S e() { return 1001001001; }

int n, m, k;
vector<vector<int>> edges;
vector<int> in;
segtree<S, op, e> st;
vector<vector<int>> ans;
vector<int> acc;

int dfs(int x) {
  if (x == n) {
    ans.push_back(acc);
    if ((int) ans.size() == k) {
      return 1;
    } else {
      return 0;
    }
  }
  int l = 0;
  while (l < n) {
    int u = st.prod(l, n);
    if (u == 1001001001) {
      break;
    }
    for (auto v : edges[u]) {
      in[v]--;
      if (in[v] < 0) return -1;
      if (in[v] == 0) st.set(v, v);
    }
    acc.push_back(u);
    st.set(u, 1001001001);
    auto ret = dfs(x + 1);
    if (ret != 0) {
      return ret;
    }
    st.set(u, u);
    acc.pop_back();
    for (auto v : edges[u]) {
      if (in[v] == 0) st.set(v, 1001001001);
      in[v]++;
    }
    l = u + 1;
  }
  return 0;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  edges = vector<vector<int>>(n);
  in = vector<int>(n);
  vector<int> in2(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges[a].push_back(b);
    in[b] += 1;
    in2[b] += 1;
  }
  vector<int> to;
  st = segtree<S, op, e>(n);
  for (int i = 0; i < n; i++) {
    if (in[i] == 0) {
      st.set(i, i);
      to.push_back(i);
    }
  }
  for (int i = 0; i < (int) to.size(); i++) {
    int u = to[i];
    for (auto v : edges[u]) {
      in2[v]--;
      if (in2[v] == 0) to.push_back(v);
    }
  }
  if ((int) to.size() < n) {
    cout << -1 << endl;
    return 0;
  }
  auto ret = dfs(0);
  if (ret == 1) {
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
        cout << ans[i][j] + 1 << (j == n - 1 ? "\n" : " ");
      }
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
