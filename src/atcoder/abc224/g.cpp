#include <bits/stdc++.h>
using namespace std;

// A->Bという選択は意味を成さないので、AのみとB->A(0回含む)の2パターンだけ考えればOK
// 「BでT以下の範囲Rに入ってから、Aで進む」のRを決めると、期待値を求めることができる
// 期待値の式は N/R*B+(R-1)/2*A であり、これは下に凸なので三分探索で期待値の最小を求められる
// 三分探索の際はRを実数で探索し、探索後に期待値の式にfloor(R)とceil(R)を代入すればOK
int main() {
  int n, s, t, a, b;
  cin >> n >> s >> t >> a >> b;
  long double l = 1, r = t;
  auto calc = [&](long double r) {
    return n / r * b + (r - 1) / 2 * a;
  };
  for (int i = 0; i < 100; i++) {
    auto lr = l + (r - l) / 3 * 1;
    auto rl = l + (r - l) / 3 * 2;
    if (calc(lr) < calc(rl)) {
      r = rl;
    } else {
      l = lr;
    }
  }
  auto ans = min(calc(floor(l)), calc(ceil(l)));
  if (s <= t) {
    ans = min(ans, (long double) (t - s) * a);
  }
  cout << fixed << setprecision(20) << ans << endl;
  return 0;
}
