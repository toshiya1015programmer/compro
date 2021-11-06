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
  long long minx = 1e18, maxx = -1;
  long long miny = 1e18, maxy = -1;
  vector<Point> coords(n);
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    coords[i] = Point { x, y };
    minx = min(minx, x), miny = min(miny, y);
    maxx = max(maxx, x), maxy = max(maxy, y);
  }
  long long ans = (maxx - minx + 1) * (maxy - miny + 1);
  sort(coords.begin(), coords.end());
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
    for (int i = 0; i < points.size() - 1; i++) {
      auto cnt = 0ll;
      auto slope = points[i + 1] - points[i];
      if (slope.x < 0) slope.x *= -1;
      if (slope.y < 0) slope.y *= -1;
      if (slope.x != 0 && slope.y != 0) {
        auto c = __gcd(slope.x, slope.y);
        cnt += ((slope.x / c + 1) * (slope.y / c + 1) / 2 - 1) * c;
        cnt += (slope.x / c) * (slope.y / c) * (c - 1) * c / 2;
      }
      long long lst;
      if (k == 0) {
        lst = maxy - max(points[i].y, points[i + 1].y);
      } else {
        lst = min(points[i].y, points[i + 1].y) - miny;
      }
      cnt += slope.x * lst;
      ans -= cnt;
    }
  }
  ans -= n;
  cout << ans << endl;
  return 0;
}
