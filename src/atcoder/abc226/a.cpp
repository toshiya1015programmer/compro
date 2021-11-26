#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  char c;
  cin >> x >> c >> y;
  y /= 100;
  if (y >= 5) x += 1;
  cout << x << endl;
  return 0;
}
