#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define popcount __builtin_popcountll
using namespace std;
using namespace atcoder;

int main() {
  long long K;
  cin >> K;
  vector<long long> d;
  // 約数の個数が多いもの（高度合成数）の一覧
  // https://gist.github.com/dario2994/fb4713f252ca86c1254d
  // 10^12以下で最大の高度合成数は963761198400で、約数の個数は6720
  for (long long i = 1; i * i <= K; i++) {
    if (K % i == 0) {
      d.push_back(i);
      if (i != K / i) d.push_back(K / i);
    }
  }
  sort(d.begin(), d.end());
  int ans = 0;
  int n = d.size();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (d[i] > K / d[j]) {
        break;
      }
      if (K % (d[i] * d[j]) != 0) {
        continue;
      }
      long long x = K / (d[i] * d[j]);
      if (x >= d[j]) {
        ans += 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
