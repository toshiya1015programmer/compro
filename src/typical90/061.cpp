#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  deque<int> deq;
  for (int i = 0; i < q; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) deq.push_front(x);
    else if (t == 2) deq.push_back(x);
    else {
      cout << deq[x - 1] << '\n';
    }
  }
  return 0;
}
