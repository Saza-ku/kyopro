#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
  int N, L;
  cin >> N >> L;
  vector<int> dp(N+L, 0);
  dp[0] = 1;
  for (int i = 0; i < N; i++) {
    dp[i+1] += dp[i];
    dp[i+L] += dp[i];
    dp[i+1] %= mod;
    dp[i+L] %= mod;
  }

  cout << dp[N] << endl;
}
