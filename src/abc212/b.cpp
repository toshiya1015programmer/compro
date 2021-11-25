#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;
  {
    string t = s;
    sort(t.begin(), t.end());
    if (t[0] == t[3]) {
      cout << "Weak" << endl;
      return 0;
    }
  }
  if (s == "9012" || s == "8901" || s == "7890") {
    cout << "Weak" << endl;
    return 0;
  }
  bool ok = true;
  for (int i = 0; i < 3; i++) {
    if (s[i] + 1 != s[i + 1]) ok = false;
  }
  if (ok) {
    cout << "Weak" << endl;
  } else {
    cout << "Strong" << endl;
  }
  return 0;
}
