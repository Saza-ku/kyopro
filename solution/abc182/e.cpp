#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int H, W, N, M;
  cin >> H >> W >> N >> M;
  vector<vector<int>> table(H, vector<int>(W, 0));

  rep (i, N) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    table[a][b] = 1;
  }
  rep (i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    table[a][b] = -100;
  }

  vector<vector<int>> a = table;
  vector<vector<int>> b = table;

  rep(i, H) {
    rep (j, W-1) {
      if (a[i][j] > 0 && a[i][j+1] >= 0) {
        a[i][j+1] = 1;
      }
    }
    for (int j = W - 1; j > 0; j--) {
      if (a[i][j] > 0 && a[i][j-1] >= 0) {
        a[i][j-1] = 1;
      }
    }
  }

  rep (j, W) {
    rep (i, H-1) {
      if (b[i][j] > 0 && b[i+1][j] >= 0) {
        b[i+1][j] = 1;
      }
    }
    for (int i = H - 1; i > 0; i--) {
      if (b[i][j] > 0 && b[i-1][j] >= 0) {
        b[i-1][j] = 1;
      }
    }
  }

  int res = 0;
  rep (i, H) {
    rep (j, W) {
      res += a[i][j] + b[i][j] > 0 ? 1 : 0;
    }
  }

  cout << res << endl;
}
