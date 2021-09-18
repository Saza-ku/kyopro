#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const long long INF = 1e18;

int main() {
  vector<vector<vector<ll>>> dp(310, vector<vector<ll>>(603, vector<ll>(603)));
  int N, X, Y;
  cin >> N >> X >> Y;

  rep(i, 305){
  rep(j, 603) {
    rep(k, 603) {
      dp[i][j][k] = INF;
    }
  }}

  dp[0][0][0] = 0;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    rep(j, 603) {
      rep(k, 603) {
        dp[i+1][j][k] = min(dp[i][j][k], dp[i+1][j][k]);
        if (0 <= j - a && j - a <= 602 &&
            0 <= k - b && k - b <= 602) {
          dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j-a][k-b]+1);
        }
      }
    }
  }

  ll res = INF;
  rep(j, 603) {
    rep(k, 603) {
      if (j >= X && k >= Y) {
        // cout << dp[N][j][k] << endl;
        res = min(res, dp[N][j][k]);
      }
    }
  }
  if (res != INF) cout << res << endl;
  else cout << -1 << endl;
}
