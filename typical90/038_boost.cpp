#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

cpp_int gcd(cpp_int a, cpp_int b) {
  if (a % b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  cpp_int a, b;
  cin >> a >> b;
  cpp_int g = gcd(a, b);
  if (a * b / g > 1000000000000000000ll) {
    cout << "Large" << endl;
  } else {
    cout << a * b / g << endl;
  }
  return 0;
}
