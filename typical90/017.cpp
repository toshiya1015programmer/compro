#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using P = tuple<int, int, char, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> L(m), R(m);
  vector<P> lrs;
  set<int> se;
  for (int i = 0; i < m; i++) {
    cin >> L[i] >> R[i];
    se.insert(L[i]);
    se.insert(R[i]);
    lrs.emplace_back(L[i], -1001001001, 'l', i);
    lrs.emplace_back(R[i], -L[i], 'r', i);
  }
  sort(lrs.begin(), lrs.end());
  vector<int> za;
  for (auto s : se) za.emplace_back(s);
  fenwick_tree<int> ft(za.size());
  long long ans = 0;
  for (int i = 0; i < lrs.size(); i++) {
    int _, idx, q;
    char ch;
    tie(_, q, ch, idx) = lrs[i];
    if (ch == 'l') {
      int x = lower_bound(za.begin(), za.end(), L[idx]) - za.begin();
      ft.add(x, 1);
    } else {
      int l = lower_bound(za.begin(), za.end(), L[idx]) - za.begin() + 1;
      int r = lower_bound(za.begin(), za.end(), R[idx]) - za.begin();
      ans += ft.sum(l, r);
      int x = lower_bound(za.begin(), za.end(), L[idx]) - za.begin();
      ft.add(x, -1);
    }
  }
  cout << ans << endl;
  return 0;
}
