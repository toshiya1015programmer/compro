#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  set<pair<int, int>> se;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int g = abs(__gcd(x[j] - x[i], y[j] - y[i]));
      se.emplace((x[j] - x[i]) / g, (y[j] - y[i]) / g);
    }
  }
  cout << se.size() << endl;
  return 0;
}
