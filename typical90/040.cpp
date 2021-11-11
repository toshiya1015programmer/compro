#include <bits/stdc++.h>
#include <atcoder/maxflow>
#define INF 1001001001001001ll
using namespace std;
using namespace atcoder;

int main() {
  const int e7 = 10000000;
  int n, w;
  cin >> n >> w;
  mf_graph<long long> g(n + 2);
  int s = n, t = n + 1;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    g.add_edge(s, i, e7 - (a[i] - w));
    g.add_edge(i, t, e7);
  }
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int c;
      cin >> c;
      c--;
      g.add_edge(i, c, INF);
    }
  }
  auto ans = (long long) e7 * n - g.flow(s, t);
  cout << ans << endl;
  return 0;
}
