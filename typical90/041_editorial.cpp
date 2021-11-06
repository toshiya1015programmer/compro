#include <bits/stdc++.h>
using namespace std;

struct Point {
  long long x, y;
};
Point operator+(const Point& a, const Point& b) {
  return Point { a.x + b.x, a.y + b.y };
}
Point operator-(const Point& a, const Point& b) {
  return Point { a.x - b.x, a.y - b.y };
}
bool operator<(const Point& a, const Point& b) {
  return a.x != b.x ? a.x < b.x : a.y < b.y;
}
long long cross(Point a, Point b) {
  return a.x * b.y - a.y * b.x;
}

int main() {
  int n;
  cin >> n;
  vector<Point> coords(n);
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    coords[i] = Point { x, y };
  }
  sort(coords.begin(), coords.end());
  vector<Point> ps;
  // 凸包
  for (int k = 0; k < 2; k++) {
    vector<Point> points;
    for (int i = 0; i < n; i++) {
      if (points.size() < 2) {
        points.push_back(coords[i]);
        continue;
      }
      while (points.size() >= 2) {
        int sz = points.size();
        auto p1 = points[sz - 1] - points[sz - 2];
        auto p2 = coords[i] - points[sz - 2];
        if (k == 0 ? (cross(p1, p2) < 0) : (cross(p1, p2) > 0)) {
          break;
        }
        points.pop_back();
      }
      points.push_back(coords[i]);
    }
    if (k == 1) {
      reverse(points.begin(), points.end());
    }
    for (int i = 0; i < points.size() - 1; i++) {
      ps.push_back(points[i]);
    }
  }
  // ピックの定理 : S = i + b/2 - 1
  //   S : 多角形の面積
  //   i : 内部にある格子点数
  //   b : 辺上にある格子点数
  // 多角形の面積は、符号付き面積（ベクトルの外積）を使うことで求められる。
  long long s = 0;
  long long b = 0;
  for (int i = 0; i < ps.size(); i++) {
    int j = (i + 1) % ps.size();
    s += cross(ps[i], ps[j]);
    auto d = ps[i] - ps[j];
    if (d.x == 0 || d.y == 0) {
      b += 1;
    } else {
      if (d.x < 0) d.x *= -1;
      if (d.y < 0) d.y *= -1;
      auto g = __gcd(d.x, d.y);
      b += g;
    }
  }
  auto ans = (abs(s) - b + 2) / 2 + b - n;
  cout << ans << endl;
  return 0;
}
