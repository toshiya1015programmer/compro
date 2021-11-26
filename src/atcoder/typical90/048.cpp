#include <bits/stdc++.h>
using namespace std;
using T = tuple<int, int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  priority_queue<T> pq;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    pq.emplace(b[i], i, 0);
  }
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    int point, index, num;
    tie(point, index, num) = pq.top();
    pq.pop();
    ans += point;
    if (num == 0) {
      pq.emplace(a[index] - b[index], index, 1);
    }
  }
  cout << ans << endl;
  return 0;
}
