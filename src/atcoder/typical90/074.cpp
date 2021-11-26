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
  return 0;
}
