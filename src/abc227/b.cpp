#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    cnt[s[i]] += 1;
  }
  for (int a = 1; a <= 1000; a++) {
    for (int b = 1; b <= 1000; b++) {
      int sum = 4 * a * b + 3 * a + 3 * b;
      if (cnt.count(sum) > 0) {
        cnt[sum] = 0;
      }
    } 
  }
  int ans = 0;
  for (auto p : cnt) {
    ans += p.second;
  }
  cout << ans << endl;
  return 0;
};
