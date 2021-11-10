#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
using T = tuple<int, int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<T, vector<T>, greater<T>> q;
  for (int i = 0; i < m; i++) {
    int c, u, v;
    cin >> c >> u >> v;
    u--;
    q.emplace(c, u, v);
  }
  long long ans = 0;
  dsu dsu(n + 1);
  while (q.size()) {
    int c, u, v;
    tie(c, u, v) = q.top();
    q.pop();
    if (!dsu.same(u, v)) {
      dsu.merge(u, v);
      ans += c;
    }
  }
  if (dsu.size(0) != n + 1) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
