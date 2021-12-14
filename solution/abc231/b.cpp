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
  map<string, int> m;
  rep (i, N) {
    string s;
    cin >> s;
    if (m.count(s)) {
      m[s]++;
    }
    else {
      m[s] = 1;
    }
  }

  int MAX = 0;
  string res;
  for (auto p : m) {
    int x;
    string s;
    tie(s, x) = p;
    if (MAX < x) {
      MAX = x;
      res = s;
    }
  }
  cout << res << endl;
}
