#include <bits/stdc++.h>
using namespace std;

struct Fraction {
  long long bottom, top;
};
bool operator<(const Fraction& a, const Fraction& b) {
  return a.top * b.bottom < a.bottom * b.top;
}
bool operator<=(const Fraction& a, const Fraction& b) {
  return a.top * b.bottom <= a.bottom * b.top;
}

int main() {
  int n;
  cin >> n;
  vector<pair<Fraction, Fraction>> arr;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr.emplace_back(Fraction { x - 1, y }, Fraction { x, y - 1 });
  }
  sort(arr.begin(), arr.end());
  auto now = Fraction { 1, 0 };
  int ans = 0;
  for (int i = 0; i < arr.size(); i++) {
    Fraction a, b;
    tie(b, a) = arr[i];
    if (now <= a) {
      now = b;
      ans += 1;
    }
  }
  cout << ans << endl;
  return 0;
};
