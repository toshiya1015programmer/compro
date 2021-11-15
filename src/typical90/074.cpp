#include <bits/stdc++.h>
using namespace std;

long long solve(string s) {
  long long ans = 0;
  long long acc = 1;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == 'b') ans += acc * 1;
    if (s[i] == 'c') ans += acc * 2;
    acc *= 2;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  cout << solve(s) << endl;
  // vector<string> ss = [&]() {
  //   string abc = "abc";
  //   vector<string> ss;
  //   string t;
  //   auto dfs = [&](auto dfs, int x = 0) {
  //     if (x == n) {
  //       ss.push_back(t);
  //       return;
  //     }
  //     for (int i = 0; i < 3; i++) {
  //       t.push_back(abc[i]);
  //       dfs(dfs, x + 1);
  //       t.pop_back();
  //     }
  //   };
  //   dfs(dfs);
  //   return ss;
  // }();
  // // simple
  // map<string, int> dp;
  // dp[string(n, 'a')] = 0;
  // auto dfs = [&]() {
  //   auto dfs = [&](auto dfs, string s) -> int {
  //     if (dp.count(s) > 0) {
  //       return dp[s];
  //     }
  //     int ret = 0;
  //     for (int i = 0; i < n; i++) {
  //       if (s[i] == 'a') continue;
  //       string t = s;
  //       t[i] -= 1;
  //       for (int j = 0; j < i; j++) {
  //         t[j] += 1;
  //         if (t[j] == 'd') t[j] = 'a';
  //       }
  //       auto r = dfs(dfs, t) + 1;
  //       if (ret < r) {
  //         ret = r;
  //       }
  //     }
  //     return dp[s] = ret;
  //   };
  //   return dfs;
  // }();
  // for (int i = 0; i < (int) ss.size(); i++) {
  //   int ans = dfs(dfs, ss[i]);
  //   cout << ss[i] << " " << ans << " " << solve(ss[i]) << '\n';
  // }
  return 0;
}
