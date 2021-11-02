#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
ll mod = 1e9 + 7;

int main() {
  ll N;
  cin >> N;
  ll K;
  cin >> K;
  vector<vector<ll>> v(N, vector<ll>(K));
  vector<vector<ll>> dp(110, vector<ll>(10010));
  rep (i, N) rep (j, K) cin >> v[i][j];
  rep (i, 110) rep (j, 10010) dp[i][j] = 0;

  rep (i, K) dp[0][i] = 1;
  rep (i, N-1) {
    vector<ll> s(K+1, 0);
    rep (j, K) s[j+1] = (s[j] + dp[i][j]) % mod;
    rep (j, K) {
      int index = upper_bound(v[i].begin(), v[i].end(), v[i+1][j]) - v[i].begin();
      dp[i+1][j] = s[index];
    }
  }

  ll res = 0;
  rep (i, K) {
    res += dp[N-1][i];
    res %= mod;
  }
  cout << res << endl;
}
