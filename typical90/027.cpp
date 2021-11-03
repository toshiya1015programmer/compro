#include <bits/stdc++.h>
using namespace std;

int main() {
  set<string> se;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (se.count(s) > 0) {
      continue;
    }
    se.insert(s);
    cout << i + 1 << '\n';
  }
  return 0;
}
