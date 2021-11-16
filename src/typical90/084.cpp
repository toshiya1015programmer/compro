#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int main() {
  int n;
  string s;
  cin >> n >> s;
  long long ans = 0;
  int r = 0;
  int cnto = 0;
  int cntx = 0;
  for (int l = 0; l < n; ) {
    while (r < n && (cnto == 0 || cntx == 0)) {
      if (s[r] == 'o') cnto += 1;
      else cntx += 1;
      r += 1;
    }
    if (cnto != 0 && cntx != 0) {
      ans += (n - r) + 1;
    }
    if (s[l] == 'o') cnto -= 1;
    else cntx -= 1;
    l += 1;
  }
  cout << ans << endl;
  return 0;
}
