#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<string> s;

  for (int i = 0; i < N; i++) {
    string str; cin >> str;
    if (!s.count(str)) {
      cout << i + 1 << endl;
      s.insert(str);
    }
  }
}
