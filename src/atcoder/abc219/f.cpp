#include <bits/stdc++.h>
using namespace std;

/**
 * x=0かつy=0のときは全く同じ経路をK回通るので、最初の1回のマスの数が答え
 * それ以外の場合、x=0のときはxとyを入れ替えることでx!=0にでき、
 * 更にx<0のときはx、yに-1を掛けることでx>0にできるので、以降はx>0として考えられる
 * N個の点を「重複するかもしれないグループ」に分ける
 * そして同じグループにある複数の点をX座標の昇順でソートして、
 * 前から順にしゃくとりっぽいことをしていけば答えが求まる
 */
int main() {
  string s;
  cin >> s;
  int n = s.size();
  long long K;
  cin >> K;
  set<pair<int, int>> se;
  int x = 0, y = 0;
  se.emplace(0 + n * 10, 0 + n * 10);
  for (int i = 0; i < n; i++) {
    switch (s[i]) {
      case 'R': x++; break;
      case 'L': x--; break;
      case 'U': y++; break;
      case 'D': y--; break;
    }
    se.emplace(x + n * 10, y + n * 10);
  }
  if (x == 0 && y == 0) {
    cout << se.size() << endl;
    return 0;
  }
  if (x == 0) {
    set<pair<int, int>> newse;
    for (auto &p : se) {
      newse.emplace(p.second, p.first);
    }
    se = newse;
    swap(x, y);
  }
  if (x < 0) {
    x *= -1, y *= -1;
  }
  map<pair<int, int>, vector<pair<int, int>>> groups;
  for (auto &p : se) {
    int s = p.first / x;
    int nx = p.first % x;
    int ny = p.second - s * y;
    groups[pair<int, int>(nx, ny)].emplace_back(p.first, p.second);
  }
  K--;
  long long ans = 0;
  for (auto &p : groups) {
    auto v = p.second;
    sort(v.begin(), v.end());
    long long w = v[0].first;
    int m = v.size();
    for (int i = 0; i < m; i++) {
      auto ne = v[i].first + K * x;
      auto ri = i < m - 1 ? v[i + 1].first : 1001001001001001001ll;
      if (ne < ri) {
        ans += (ne - w) / x + 1;
        w = ri;
      } else {
        continue;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
