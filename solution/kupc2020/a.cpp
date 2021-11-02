#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N;cin >> N;
  int x, y;
  int res = 0;
  rep (i, N) {
    int a, b;
    cin >> a >> b;
    if (i != 0) {
      res += abs(x - a) + abs(y - b);
    }
    x = a;
    y = b;
  }
  cout << res << endl;
}
