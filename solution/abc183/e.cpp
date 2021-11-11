#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int mod = 1e9 + 7;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<bool>> reachable(H, vector<bool>(W));
  rep (i, H) {
    rep (j, W) {
      char c;
      cin >> c;
      if (c == '.') reachable[i][j] = true;
      else reachable[i][j] = false;
    }
  }

  vector<vector<ll>> table(H, vector<ll>(W, 0));
  vector<vector<ll>> x(H, vector<ll>(W, 0));
  vector<vector<ll>> y(H, vector<ll>(W, 0));
  vector<vector<ll>> z(H, vector<ll>(W, 0));
  table[0][0] = 1;

  rep (i, H) {
    rep (j, W) {
      if (!reachable[i][j]) {
        continue;
      }
      if (i > 0) x[i][j] = (x[i-1][j] + table[i-1][j]) % mod;
      if (j > 0) y[i][j] = (y[i][j-1] + table[i][j-1]) % mod;
      if (i > 0 && j > 0) (z[i][j] = z[i-1][j-1] + table[i-1][j-1]) % mod;

      table[i][j] += (x[i][j] + y[i][j] + z[i][j]) % mod;
    }
  }

  cout << table[H-1][W-1] << endl;
}
