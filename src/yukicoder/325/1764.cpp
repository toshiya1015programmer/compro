#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;
  vector<deque<char>> ques(4);
  ques[0].push_back('A');
  ques[0].push_back('E');
  ques[1].push_back('B');
  ques[2].push_back('C');
  ques[3].push_back('D');
  for (int i = 0; i < k; i++) {
    int j = i % 4;
    int l = (i + 1) % 4;
    char c = ques[j].front();
    ques[j].pop_front();
    ques[l].push_back(c);
  }
  for (int i = 0; i < 4; i++) {
    string s;
    while (ques[i].size()) {
      s += ques[i].front();
      ques[i].pop_front();
    }
    cout << s << endl;
  }
  return 0;
}
