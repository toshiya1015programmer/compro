#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n, x;
  cin >> n >> x;
  x--;
  vector<int> ne(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a--;
    ne[i] = a;
  }
  set<int> se;
  while (true) {
    if (se.count(x)) break;
    se.insert(x);
    x = ne[x];
  }
  cout << se.size() << endl;
  return 0;
}
