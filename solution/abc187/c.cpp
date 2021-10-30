#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N;
  cin >> N;
  set<string> table1;
  set<string> table2;
  rep (i, N) {
    string s;
    cin >> s;
    if (s[0] == '!') {
      s.erase(0, 1);
      table2.insert(s);
    }
    else {
      table1.insert(s);
    }
  }
  for (auto p : table1) {
    if (table2.count(p)) {
      cout << p << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
}
