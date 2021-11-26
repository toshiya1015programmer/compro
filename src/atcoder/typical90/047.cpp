#include <bits/stdc++.h>
using namespace std;

template< unsigned mod >
struct RollingHash {
  vector< unsigned > hashed, power;

  inline unsigned mul(unsigned a, unsigned b) const {
    unsigned long long x = (unsigned long long) a * b;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
    return m;
  }

  RollingHash(const string &s, unsigned base = 10007) {
    int sz = (int) s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
    }
  }

  unsigned get(int l, int r) const {
    unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
    if(ret >= mod) ret -= mod;
    return ret;
  }

  unsigned connect(unsigned h1, int h2, int h2len) const {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if(ret >= mod) ret -= mod;
    return ret;
  }

  int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return (low);
  }
};

using RH = RollingHash< 1000000007 >;

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<vector<string>> ss(3);
  vector<vector<string>> tt(3);
  string S = "RGB";
  for (int i = 0; i < 3; i++) {
    string w;
    w = s;
    for (int j = 0; j < n; j++) {
      if (w[j] != S[i]) w[j] = 'X';
    }
    ss[i].push_back(w);
    w = s;
    for (int j = 0; j < n; j++) {
      if (w[j] == S[i]) w[j] = 'X';
    }
    ss[i].push_back(w);
    w = t;
    for (int j = 0; j < n; j++) {
      if (w[j] != S[i]) w[j] = 'X';
    }
    tt[i].push_back(w);
    w = t;
    for (int j = 0; j < n; j++) {
      int k = (i + 1) % 3;
      int l = (i + 2) % 3;
      if (w[j] == S[i]) w[j] = 'X';
      else if (w[j] == S[k]) w[j] = S[l];
      else if (w[j] == S[l]) w[j] = S[k];
    }
    tt[i].push_back(w);
  }
  vector<vector<RH>> rs(3), rt(3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      RH rh1(ss[i][j]), rh2(tt[i][j]);
      rs[i].push_back(rh1);
      rt[i].push_back(rh2);
    }
  }
  int ans = 0;
  for (int k = -n + 1; k <= n - 1; k++) {
    int sl = max(0, k);
    int sr = min(n, k + n);
    int tl = max(0, -k);
    int tr = min(n, n - k);
    bool ok = false;
    for (int i = 0; i < 3; i++) {
      if (rs[i][0].get(sl, sr) == rt[i][0].get(tl, tr) && rs[i][1].get(sl, sr) == rt[i][1].get(tl, tr)) {
        ok = true;
      }
    }
    if (ok) {
      ans += 1;
    }
  }
  cout << ans << endl;
  return 0;
}
