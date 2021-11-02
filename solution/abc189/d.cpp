#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  rep (i, N) cin >> s[i];

  vector<ll> dp(N+1);
  dp[0] = 1;
  for (ll i = 0; i < N; i++) {
    if (s[i] == "AND") {
      dp[i+1] = dp[i];
    }
    else {
      dp[i+1] = dp[i] + (1LL << (i+1));
    }
  }
  cout << dp[N] << endl;
}
