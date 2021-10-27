#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W));
  int min_cnt = INF;
  rep (i, H) {
    rep (j, W) {
      cin >> a[i][j];
      min_cnt = min(min_cnt, a[i][j]);
    }
  }
  int res = 0;
  rep (i, H) {
    rep (j, W) {
      res += a[i][j] - min_cnt;
    }
  }
  cout << res << endl;
}

