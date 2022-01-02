#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  rep (i, N) cin >> a[i];

  ll res = 0;
  for (ll bit = 1; bit < (1LL << 61); bit <<= 1) {
    ll cnt_0 = 0;
    ll cnt_1 = 0;
    rep (i, N) {
      if (a[i] & bit) cnt_1++;
      else cnt_0++;
    }
    ll x = cnt_1 * cnt_0;
    x %= MOD;
    x *= (bit % MOD);
    x %= MOD;
    res += x;
    res %= MOD;
  }

  cout << res << endl;
}
