#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, n) {
    int sum = 0;
    rep(i, 3) { int s; cin >> s; sum += s; }
    p[i] = sum;
  }
  auto sp = p;
  sort(sp.begin(), sp.end());
  rep(i, n) {
    int x = upper_bound(sp.begin(), sp.end(), p[i] + 300) - sp.begin();
    int y = n - x;
    cout << (y < k ? "Yes" : "No") << '\n';
  }
  return 0;
}
