#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  long long a, b;
  cin >> a >> b;
  long long g = gcd(a, b);
  if (a > 1000000000000000000 / (b / g)) {
    cout << "Large" << endl;
  } else {
    cout << a / g * b << endl;
  }
  return 0;
}
