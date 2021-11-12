#include <bits/stdc++.h>
using namespace std;

int main() {
  long double t, l, x, y;
  cin >> t >> l >> x >> y;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    long double e;
    cin >> e;
    long double ux, uy, uz, vx, vy, vz;
    ux = 0;
    uy = -l / 2 * sin(2 * M_PI * e / t);
    uz = l / 2 * (1 - cos(2 * M_PI * e / t));
    vx = -x;
    vy = uy - y;
    vz = uz;
    ux = vx;
    uy = vy;
    uz = 0;
    if (vz == 0) {
      cout << 0 << endl;
      continue;
    }
    long double top = ux*vx + uy*vy + uz*vz;
    long double bot = sqrt(ux*ux+uy*uy+uz*uz) * sqrt(vx*vx+vy*vy+vz*vz);
    auto c = top / bot;
    auto ans = acos(c) * 180 / M_PI;
    cout << setprecision(16) << fixed << ans << '\n';
  }
  return 0;
}
