#include <bits/stdc++.h>
#include <atcoder/math>
using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bitset<300>> bs(n);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
      int a;
      cin >> a;
      a--;
      bs[i].set(a);
    }
  }
  // 行列のXORによる行基本変形（掃き出し法）
  int s = 0;
  for (int i = m - 1; i >= 0; i--) {
    bool swapped = false;
    for (int j = s; j < n; j++) {
      if (bs[j].test(i)) {
        swap(bs[s], bs[j]);
        swapped = true;
        break;
      }
    }
    if (!swapped) continue;
    for (int j = 0; j < n; j++) {
      if (j == s) continue;
      if (bs[j].test(i)) bs[j] ^= bs[s];
    }
    s += 1;
  }
  bitset<300> sm;
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    sm.set(i, v);
  }
  int now = 0;
  for (int i = m - 1; i >= 0; i--) {
    if (sm.test(i)) {
      while (now < n && !bs[now].test(i)) now += 1;
      if (now == n) {
        cout << 0 << endl;
        return 0;
      }
      sm ^= bs[now];
    }
    if (sm.none()) {
      while (now < n && !bs[now].none()) now += 1;
      int len = n - now;
      cout << pow_mod(2, len, 998244353) << endl;
      return 0;
    }
  }
  return 0;
}
