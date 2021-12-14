#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;


vector<ll> a;

ll solve(ll X) {
  if (X == 0) {
    return 0;
  }

  ll first_X = X;
  ll cnt = 0;
  while (X > 0) {
    auto iter = upper_bound(a.begin(), a.end(), X);
    iter--;
    ll x = *iter;
    cnt += X / x;
    X %= x;
  }

  return cnt;
}

ll solve_impl(ll X, map<ll, ll> &dp) {
  cout << X << endl;
  if (dp.count(X)) {
    return dp[X];
  }
  if (X == 0) {
    return 0;
  }
  auto iter = upper_bound(a.begin(), a.end(), X);
  iter--;
  if (X % *iter == 0) {
    return X / *iter;
  }

  ll res = solve(X);

  ll Y = *iter;
  ll n = 1 + X / Y;
  res = min(res, solve_impl(Y * n - X, dp) + n);

  iter++;
  if (iter != a.end()) {
    Y = *iter;
    res = min(res, solve_impl(Y - X, dp) + 1);
  }

  dp[X] = res;
  return res;
}

int main() {
  ll N, X;
  cin >> N >> X;
  a.resize(N);
  map<ll, ll> dp;
  rep (i, N) cin >> a[i];
  ll res = solve_impl(X, dp);
  cout << res << endl;
}
