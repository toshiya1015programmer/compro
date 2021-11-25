#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  vector<string> s(4);
  for (int i = 0; i < 4; i++) cin >> s[i];
  sort(s.begin(), s.end());
  if (s[0] == "2B" && s[1] == "3B" && s[2] == "H" && s[3] == "HR") {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
