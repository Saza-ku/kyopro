#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  string s, t;
  cin >> s >> t;
  int a, b;
  cin >> a >> b;
  string u;
  cin >> u;

  if (s == u) {
    cout << a-1 << " " << b << endl;
  }
  else {
    cout << a << " " << b - 1 << endl;
  }
}
