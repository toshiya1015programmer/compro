#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using vvm = vector<vector<mint>>;

vvm matmul(vvm x, vvm y) {
  vvm res(x.size(), vector<mint>(y[0].size()));
  for (int i = 0; i < x.size(); i++)
  for (int j = 0; j < y[0].size(); j++)
  for (int k = 0; k < x[0].size(); k++) {
    res[i][j] += x[i][k] * y[k][j];
  }
  return res;
}

vvm matpow(vvm x, long long n) {
  vvm res(x.size(), vector<mint>(x.size()));
  for (int i = 0; i < x.size(); i++) {
    res[i][i] = 1;
  }
  while (n) {
    if (n & 1) res = matmul(res, x);
    n >>= 1, x = matmul(x, x);
  }
  return res;
}

int main() {
  long long N, B, K;
  cin >> N >> B >> K;
  vector<int> c(K);
  for (int i = 0; i < K; i++) {
    cin >> c[i];
  }
  assert(B <= 30);
  vvm mat(B, vector<mint>(B));
  for (int i = 0; i < B; i++) {
    for (int j = 0; j < K; j++) {
      int u = i;
      int v = (i * 10 + c[j]) % B;
      mat[u][v] += 1;
    }
  }
  auto m = matpow(mat, N);
  vvm dp(1, vector<mint>(B));
  dp[0][0] = 1;
  dp = matmul(dp, m);
  cout << dp[0][0].val() << endl;
  return 0;
}
