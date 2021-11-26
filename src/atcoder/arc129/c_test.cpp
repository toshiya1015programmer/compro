#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

long long calc(int x) {
  for (int i = 1; ; i++) {
    int ni = i + 1;
    if (ni * (ni + 1) / 2 > x) {
      return i;
    }
  }
}

bool solve(string s) {
  int sum = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    sum *= 10;
    sum += s[i] - '0';
    sum %= 7;
  }
  if (sum == 0) {
    // cerr << s << endl;
  }
  return sum == 0;
}

int main() {
  string s;
  cin >> s;
  int n = s.size();
  {
    vector<int> sums(n + 1);
    int acc = 1;
    for (int i = n - 1; i >= 0; i--) {
      sums[i] = ((s[i] - '0') * acc + sums[i + 1]) % 7;
      acc = acc * 10 % 7;
    }
    rep(i, n) cerr << sums[i] << (i == n - 1 ? '\n' : ' ');
    map<int, int> cnt;
    rep(i, n + 1) cnt[sums[i]] += 1;
    long long ans = 0;
    for (auto p : cnt) {
      long long x = p.second;
      ans += x * (x - 1) / 2;
    }
    cerr << ans << endl;
  }
  return 0;
}
