#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int main() {
  int n = 1 << 20;
  set<int> se;
  rep(i, n * 2) {
    se.insert(i);
  }
  vector<long long> vals(n, -1);
  int q;
  cin >> q;
  rep(qi, q) {
    int t;
    long long x;
    cin >> t >> x;
    if (t == 2) {
      x = (x - 1) % n;
      cout << vals[x] << endl;
      continue;
    }
    int h = (x - 1) % n;
    int j = (*se.lower_bound(h)) % n;
    vals[j] = x;
    se.erase(j), se.erase(j + n);
  }
  return 0;
}
