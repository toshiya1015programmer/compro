#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  // simple
  {
    vector<string> route;
    map<string, int> dp;
    dp[string(n, 'a')] = 0;
    int ma = 0;
    auto dfs = [&](auto dfs, string s) -> int {
      if (dp.count(s) > 0) {
        if (ma < (int) route.size()) {
          ma = route.size();
          cerr << route.size() << endl;
          for (auto s : route) {
            cerr << s << endl;
          }
        }
        return dp[s];
      }
      int ret = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'a') continue;
        string t = s;
        t[i] -= 1;
        for (int j = 0; j < i; j++) {
          t[j] += 1;
          if (t[j] == 'd') t[j] = 'a';
        }
        route.push_back(t);
        auto r = dfs(dfs, t) + 1;
        route.pop_back();
        if (ret < r) {
          ret = r;
        }
      }
      return dp[s] = ret;
    };
    route.push_back(s);
    int ans = dfs(dfs, s);
    cout << ans << endl;
  }
  return 0;
}
