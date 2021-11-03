#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  long long p;
  cin >> n >> k >> p;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int h = n / 2;
  vector<vector<map<long long, int>>> mp(2, vector<map<long long, int>>(n + 1));
  for (int i = 0; i < (1 << h); i++) {
    int cnt = __builtin_popcount(i);
    long long sum = 0;
    for (int j = 0; j < h; j++) {
      if (i & (1 << j)) {
        sum += a[j];
      }
    }
    mp[0][cnt][sum] += 1;
  }
  for (int i = 0; i < (1 << (n - h)); i++) {
    int cnt = __builtin_popcount(i);
    long long sum = 0;
    for (int j = 0; j < n - h; j++) {
      if (i & (1 << j)) {
        sum += a[h + j];
      }
    }
    mp[1][cnt][sum] += 1;
  }
  vector<vector<vector<long long>>> nums(2, vector<vector<long long>>(n + 1));
  vector<vector<vector<long long>>> cnts(2, vector<vector<long long>>(n + 1));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j <= max(h, n - h); j++) {
      for (auto p : mp[i][j]) {
        nums[i][j].push_back(p.first);
        cnts[i][j].push_back(p.second);
      }
    }
  }
  for (int j = 0; j <= n; j++) {
    for (int i = 1; i < cnts[1][j].size(); i++) {
      cnts[1][j][i] += cnts[1][j][i - 1];
    }
  }
  long long ans = 0;
  for (int j = 0; j <= h; j++) {
    for (int i = 0; i < nums[0][j].size(); i++) {
      auto num = nums[0][j][i];
      if (num > p || j > k) break;
      auto rest = p - num;
      auto l = k - j;
      int len = upper_bound(nums[1][l].begin(), nums[1][l].end(), rest) - nums[1][l].begin();
      if (len > 0) {
        ans += cnts[0][j][i] * cnts[1][l][len - 1];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
