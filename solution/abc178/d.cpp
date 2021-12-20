#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

ll repeat_squaring(ll x, ll n, ll mod) {
  x %= mod;
  if(n == 0) {
    return 1;
  }
  else if(n % 2 == 0) {
    long long t = repeat_squaring(x, n / 2, mod);
    return t * t % mod;
  }
  else {
    return x * repeat_squaring(x, n - 1, mod) % mod;
  }
}

ll mod_rev(ll n, ll mod) {
  return repeat_squaring(n, mod - 2, mod);
}

ll fac_mod(ll m, ll mod) {
  static vector<ll> f_(10000000, -1);
  f_[0] = 1;
  if (f_[m] != -1) {
    return f_[m];
  }
  return f_[m] = fac_mod(m-1, mod) * m % mod;
}

ll com_mod(ll n, ll k, ll mod) {
  ll ret = fac_mod(n, mod) * mod_rev(fac_mod(k, mod), mod) % mod;
  ret = ret * mod_rev(fac_mod(n - k, mod), mod) % mod;
  return ret;
}

int main() {
  ll N;
  cin >> N;
  ll res = 0;
  rep (i, N) {
    if (i == 0) continue;
    ll num = i;
    ll remainder = N - num * 3;
    if (remainder < 0) break;
    res += com_mod(remainder + num - 1, remainder, MOD);
    res %= MOD;
  }

  cout << res << endl;
}
