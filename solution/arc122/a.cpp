#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const ll MINUS_MOD = MOD - 1;

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  rep (i, N) cin >> a[i];

  vector<vector<ll>> dp(N, vector<ll>(2));
  dp[0][0] = 1;
  dp[0][1] = 0;

  rep (i, N-1) {
    dp[i+1][0] = (dp[i][0] + dp[i][1]) % MOD;
    dp[i+1][1] = dp[i][0] % MOD;
    cerr << dp[i+1][0] << " " << dp[i+1][1] << endl;
  }

  ll res = 0;
  for (int i = N - 1; i >= 0; i--) {
    cerr << dp[i][0] << " " << dp[i][1] << endl;
    if (i == 0) {
      res += (dp[i][0] + dp[i][1]) * a[i] % MOD;
      res %= MOD;
      break;
    }

    res += dp[i][0] * a[i];
    res %= MOD;

    ll minus_a = a[i] * MINUS_MOD;
    minus_a %= MOD;
    res += (dp[i][1] * minus_a) % MOD;
    res %= MOD;

    ll plus_count = dp[i][1] * 2 % MOD;
    ll minus_count = (dp[i][0] - dp[i][1]) % MOD;
    dp[i-1][0] = plus_count;
    dp[i-1][1] = minus_count;
  }
  
  cout << res << endl;
}
