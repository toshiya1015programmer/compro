#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> ans;
  for (int i = 0; i < (1 << n); i++) {
    bool minus = false;
    int acc = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        acc += 1;
      } else {
        acc -= 1;
      }
      if (acc < 0) minus = true;
    }
    if (!minus && acc == 0) {
      string s;
      for (int j = 0; j < n; j++) {
        s += (i & (1 << j)) ? '(' : ')';
      }
      ans.emplace_back(s);
    }
  }
  sort(ans.begin(), ans.end());
  for (auto s : ans) {
    cout << s << '\n';
  }
  return 0;
}
