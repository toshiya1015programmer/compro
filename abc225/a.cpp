#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  sort(s.begin(), s.end());
  do {
    ans += 1;
  } while (next_permutation(s.begin(), s.end()));
  cout << ans << endl;
  return 0;
};
