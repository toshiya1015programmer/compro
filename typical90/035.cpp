#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;

struct HLDecomposition {
  vector<vector<int>> g;
  vector<int> vid;
  vector<int> out;
  vector<int> head;
  vector<int> par;
  vector<int> ddep;
  HLDecomposition(vector<vector<int>> g) : g(g) {
    int n = g.size();
    vid = vector<int>(n);
    out = vector<int>(n);
    head = vector<int>(n);
    par = vector<int>(n, -1);
    ddep = vector<int>(n);
    {
      vector<int> sz(n);
      auto dfs = [&](auto dfs, int u, int p) -> void {
        sz[u] = 1;
        for (auto &v : g[u]) if (v != p) {
          par[v] = u;
          dfs(dfs, v, u);
          sz[u] += sz[v];
          if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
        }
      };
      dfs(dfs, 0, -1);
    }
    {
      int t = 0;
      auto dfs = [&](auto dfs, int u, int p) -> void {
        vid[u] = t++;
        for (auto v : g[u]) if (v != p) {
          if (v == g[u][0]) {
            head[v] = head[u];
            ddep[v] = ddep[u];
          } else {
            head[v] = v;
            ddep[v] = ddep[u] + 1;
          }
          dfs(dfs, v, u);
        }
        out[u] = t;
      };
      dfs(dfs, 0, -1);
    }
  }
  void for_each(int u, int v, function<void(int, int)> f) {
    while (true) {
      if (ddep[u] > ddep[v]) swap(u, v);
      if (head[u] == head[v]) {
        f(min(vid[u], vid[v]), max(vid[u], vid[v]) + 1);
        return;
      }
      f(vid[head[v]], vid[v] + 1);
      v = par[head[v]];
    }
  }
  void for_each_edge(int u, int v, function<void(int, int)> f) {
    while (true) {
      if (ddep[u] > ddep[v]) swap(u, v);
      if (head[u] == head[v]) {
        f(min(vid[u], vid[v]) + 1, max(vid[u], vid[v]) + 1);
        return;
      }
      f(vid[head[v]], vid[v] + 1);
      v = par[head[v]];
    }
  }
  int lca(int u, int v) {
    while (true) {
      if (ddep[u] > ddep[v]) swap(u, v);
      if (head[u] == head[v]) {
        return vid[u] < vid[v] ? u : v;
      }
      v = par[head[v]];
    }
  }
  pair<int, int> subtree(int u) {
    return make_pair(vid[u], out[u]);
  }
  pair<int, int> subtree_edge(int u) {
    return make_pair(vid[u] + 1, out[u]);
  }
  int operator[](int k) {
    return vid[k];
  }
};

struct S { int value; int size; };
S op(S a, S b) { return S { a.value + b.value, a.size + b.size }; }
S e() { return S { 0, 1 }; }
using F = int;
S mapping(F f, S x) { return f == -1 ? x : S { f * x.size, x.size }; }
F composition(F f, F g) { return f == -1 ? g : f; }
F id() { return -1; }

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  HLDecomposition hld(g);
  int q;
  cin >> q;
  lazy_segtree<S, op, e, F, mapping, composition, id> lst(n);
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    int prev = -1;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      a--;
      if (j == 0) { prev = a; continue; }
      hld.for_each(prev, a, [&](int l, int r) {
        lst.apply(l, r, 1);
      });
      prev = a;
    }
    auto ans = lst.all_prod();
    cout << ans.value - 1 << endl;
    lst.apply(0, n, 0);
  }
  return 0;
}
