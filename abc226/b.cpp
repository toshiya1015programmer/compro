#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<vector<int>> vec;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
      cin >> a[i];
    }
    vec.insert(a);
  }
  cout << vec.size() << endl;
  return 0;
}
