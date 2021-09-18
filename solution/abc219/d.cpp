#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const long long INF = 1e9;

// クソでか配列はスタック領域に置けない（セグフォになる）
int dp[305][305][305];
int main() {
  int N, X, Y;
  cin >> N >> X >> Y;

  rep(i, 305) {
    rep(j, 305) {
      rep(k, 305) {
        dp[i][j][k] = INF;
      }
    }
  }

  dp[0][0][0] = 0;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    rep (j, 305) {
      rep (k, 305) {
        dp[i+1][j][k] = min(dp[i][j][k], dp[i+1][j][k]);
        int nj = min(j + a, X);
        int nk = min(k + b, Y);
        dp[i+1][nj][nk] = min(dp[i+1][nj][nk], dp[i][j][k] + 1);
      }
    }
  }
  int res = dp[N][X][Y];
  if (res == INF) {
    cout << -1 << endl;
    return 0;
  }
  cout << dp[N][X][Y] << endl;
}
