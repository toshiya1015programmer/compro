#include <bits/stdc++.h>
using namespace std;

int ketaseki(string x) {
  int r = 1;
  for (int i = 0; i < x.size(); i++) {
    int k = x[i] - '0';
    if (k > 0) {
      r *= k;
    }
  }
  return r;
}

bool match(string x, long long y) {
  map<int, int> cnt;
  for (int i = 0; i < x.size(); i++) {
    int k = x[i] - '0';
    if (k > 0) {
      cnt[k] += 1;
    }
  }
  while (y) {
    int k = y % 10;
    if (k == 0 || cnt[k] == 0) {
      return false;
    }
    cnt[k] -= 1;
    y /= 10;
  }
  for (auto p : cnt) {
    if (p.second > 0) {
      return false;
    }
  }
  return true;
}

int main() {
  long long n, b;
  cin >> n >> b;
  int ans = 0;
  {
    bool ok = false;
    auto _b = b;
    while (_b) {
      if (_b % 10 == 0) {
        ok = true;
      }
      _b /= 10;
    }
    if (ok) {
      if (n >= b) {
        ans += 1;
      }
    }
  }
  vector<int> p(21);
  for (int i = 0; i < 9; i++) {
    p[i] = 1;
  }
  sort(p.begin(), p.end());
  do {
    string x;
    int now = 0;
    int acc = 0;
    for (int i = 0; i < 21; i++) {
      if (p[i]) {
        acc += 1;
      } else {
        x += (char) (acc + '0');
        now += 1;
      }
    }
    auto y = ketaseki(x) + b;
    if (match(x, y) && y <= n) {
      ans += 1;
    }
  } while (next_permutation(p.begin(), p.end()));
  cout << ans << endl;
  return 0;
}
