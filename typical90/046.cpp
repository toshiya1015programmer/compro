#include <bits/stdc++.h>
using namespace std;

int vec[3][46];

int main() {
  int n;
  cin >> n;
  for (int k = 0; k < 3; k++) {
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      vec[k][x % 46] += 1;
    }
  }
  long long ans = 0;
  for (int i = 0; i < 46; i++) {
    for (int j = 0; j < 46; j++) {
      for (int k = 0; k < 46; k++) {
        int sum = (i + j + k) % 46;
        if (sum == 0) {
          ans += (long long) vec[0][i] * vec[1][j] * vec[2][k];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
