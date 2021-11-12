#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<int>> cnt(26, vector<int>(n + 1));
  vector<vector<int>> nex(26, vector<int>(n + 1, n));
  for (int i = n - 1; i >= 0; i--) {
    cnt[s[i] - 'a'][i] += 1;
    nex[s[i] - 'a'][i] = i;
    for (int j = 0; j < 26; j++) {
      cnt[j][i] += cnt[j][i + 1];
      nex[j][i] = min(nex[j][i], nex[j][i + 1]);
    }
  }
  string ans;
  int now = 0;  // 現在どの位置にいるか
  int acc = 0;  // k と比較するもの
  while (acc < k) {
    char ch = 'a';
    while ((n - (nex[ch - 'a'][now] + 1)) + 1 + acc < k) {
      ch += 1;
    }
    ans += ch;
    acc += 1;
    now = nex[ch - 'a'][now] + 1;
  }
  cout << ans << endl;
  return 0;
}
