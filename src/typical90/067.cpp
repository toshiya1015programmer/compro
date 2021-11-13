#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
  long long ret = 0;
  long long acc = 1;
  while (x) {
    int y = x % 9;
    if (y == 8) y = 5;
    ret += acc * y;
    x /= 9, acc *= 8;
  }
  return ret;
}

long long from8(string s) {
  long long ret = 0;
  long long acc = 1;
  reverse(s.begin(), s.end());
  for (int i = 0; i < (int) s.size(); i++) {
    ret += (s[i] - '0') * acc;
    acc *= 8;
  }
  return ret;
}

string to8(long long x) {
  string s;
  while (x) {
    int y = x % 8;
    s += ((char) (y + '0'));
    x /= 8;
  }
  reverse(s.begin(), s.end());
  if (s == "") s = "0";
  return s;
}

int main() {
  string n;
  int k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    n = to8(f(from8(n)));
  }
  cout << n << endl;
  return 0;
}
