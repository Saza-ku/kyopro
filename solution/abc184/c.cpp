#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int rs, cs, rt, ct;
  cin >> rs >> cs >> rt >> ct;

  // 0
  if (rs == rt && cs == ct) {
    cout << 0 << endl;
    return 0;
  }

  // 1
  if (rs + cs == rt + ct) {
    cout << 1 << endl;
    return 0;
  }
  if (rs - cs == rt - ct) {
    cout << 1 << endl;
    return 0;
  }
  if (abs(rs - rt) + abs(cs - ct) <= 3) {
    cout << 1 << endl;
    return 0;
  }

  // 2
  if (abs(rs - rt) + abs(cs - ct) <= 6) {
    cout << 2 << endl;
    return 0;
  }
  for (int i = -3; i <= 3; i++) {
    int x = rs + i, y = cs;
    if (x + y == rt + ct) {
      cout << 2 << endl;
      return 0;
    }
    if (x - y == rt - ct) {
      cout << 2 << endl;
      return 0;
    }
  }

  if ((rs + cs) % 2 == (rt + ct) % 2) {
    cout << 2 << endl;
    return 0;
  }

  // 3
  cout << 3 << endl;
}
