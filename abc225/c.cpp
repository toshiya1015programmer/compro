#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
      b[i][j] -= 1;
    }
  }
  int s = b[0][0];
  if ((s % 7) + m > 7) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long now = s + i * 7 + j;
      if (b[i][j] != now) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
};
