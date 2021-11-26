#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  cpp_int ok = 0, ng = (cpp_int) 1 << 100;
  while (abs(ok - ng) != 1) {
    cpp_int md = (ok + ng) / 2;
    cpp_int rest = 0;
    for (int i = 0; i < k; i++) {
      rest += max((cpp_int) 0, md - a[i]);
    }
    for (int i = k; i < n; i++) {
      rest -= a[i];
    }
    (rest > 0 ? ng : ok) = md;
  }
  cout << ok << endl;
  return 0;
};
