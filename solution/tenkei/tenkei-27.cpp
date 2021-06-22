#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<string> names;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    if (names.count(s)) continue;
    cout << i+1 << endl;
    names.insert(s);
  }
}
