#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;

vector<int> ela(MAX + 1);

int main() {
  for (int i = 2; i <= MAX; i++) {
    if (ela[i] != 0) continue;
    ela[i] += 1;
    for (int j = i * 2; j <= MAX; j += i) {
      ela[j] += 1;
    }
  }
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    if (ela[i] >= k) ans += 1;
  }
  cout << ans << endl;
  return 0;
}
