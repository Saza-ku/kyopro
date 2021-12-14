#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

map<ll, ll> dp;
vector<ll> a(0);

ll solve(ll N, ll i) {
  if (dp.count(N)) {
    return dp[N];
  }
  if (N == 0) {
    return 0;
  }

  ll ret = N % a[i+1] + solve(N / a[i+1], a[i+1] / a[i]);
}

int main() {
  ll N, X;
  cin >> N >> X;
  a.resize(N);
  rep (i, N) cin >> a[i];
}
