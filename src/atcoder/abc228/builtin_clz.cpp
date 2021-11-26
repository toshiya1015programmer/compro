#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << 32 - __builtin_clz(n) << endl;
  return 0;
}
