#include <bits/stdc++.h>
using namespace std;

int main() {
  unsigned long long a, b, c;
  cin >> a >> b >> c;
  unsigned long long x = c;
  while (--b) {
    x *= c;
  }
  if (a < x) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
