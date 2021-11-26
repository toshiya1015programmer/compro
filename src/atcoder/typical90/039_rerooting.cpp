#include <bits/stdc++.h>
using namespace std;

template< typename Data, typename T >
struct ReRooting {
 
  struct Node {
    int to, rev;
    Data data;
  };
 
  using F1 = function< T(T, T) >;
  using F2 = function< T(T, Data) >;
 
  vector< vector< Node > > g;
  vector< vector< T > > ldp, rdp;
  vector< int > lptr, rptr;
  const F1 f1;
  const F2 f2;
  const T ident;
 
  ReRooting(int n, const F1 &f1, const F2 &f2, const T &ident) :
      g(n), ldp(n), rdp(n), lptr(n), rptr(n), f1(f1), f2(f2), ident(ident) {}
 
  void add_edge(int u, int v, const Data &d) {
    g[u].emplace_back((Node) {v, (int) g[v].size(), d});
    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, d});
  }
 
  void add_edge_bi(int u, int v, const Data &d, const Data &e) {
    g[u].emplace_back((Node) {v, (int) g[v].size(), d});
    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, e});
  }
 
 
  T dfs(int idx, int par) {
 
    while(lptr[idx] != par && lptr[idx] < g[idx].size()) {
      auto &e = g[idx][lptr[idx]];
      ldp[idx][lptr[idx] + 1] = f1(ldp[idx][lptr[idx]], f2(dfs(e.to, e.rev), e.data));
      ++lptr[idx];
    }
    while(rptr[idx] != par && rptr[idx] >= 0) {
      auto &e = g[idx][rptr[idx]];
      rdp[idx][rptr[idx]] = f1(rdp[idx][rptr[idx] + 1], f2(dfs(e.to, e.rev), e.data));
      --rptr[idx];
    }
    if(par < 0) return rdp[idx][0];
    return f1(ldp[idx][par], rdp[idx][par + 1]);
  }
 
  vector< T > solve() {
    for(int i = 0; i < g.size(); i++) {
      ldp[i].assign(g[i].size() + 1, ident);
      rdp[i].assign(g[i].size() + 1, ident);
      lptr[i] = 0;
      rptr[i] = (int) g[i].size() - 1;
    }
    vector< T > ret;
    for(int i = 0; i < g.size(); i++) {
      ret.push_back(dfs(i, -1));
    }
    return ret;
  }
};

using Data = int;
using T = int;

int main() {
  auto merge = [&](T a, T b) { return a + b; };
  auto lift = [&](T a, Data d) { return a + 1; };
  int n;
  cin >> n;
  ReRooting<Data, T> rr(n, merge, lift, 0);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    rr.add_edge(a, b, 0);
  }
  auto vec = rr.solve();
  long long ans = 0;
  auto dfs = [&](auto dfs, int u, int p) -> void {
    for (int i = 0; i < rr.g[u].size(); i++) {
      auto e = rr.g[u][i];
      if (e.to != p) {
        ans += (long long) rr.f2(rr.dfs(e.to, e.rev), 0) * rr.f2(rr.dfs(u, i), 0);
        dfs(dfs, e.to, u);
      }
    }
  };
  dfs(dfs, 0, -1);
  cout << ans << endl;
  return 0;
}
