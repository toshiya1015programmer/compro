#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> ans(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a > b) swap(a, b);
    ans[b] += 1;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (ans[i] == 1) cnt += 1;
  }
  cout << cnt << endl;
  return 0;
}
