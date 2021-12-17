#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

vector<ll> fac(100000 + 10);

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

ll mod_rev(ll N, ll mod) {
  return repeat_squaring(N, mod - 2, mod);
}

// N 個を K グループに分割する
ll split_paterns(ll N, ll K) {
  if (N < 0) return 0;
  ll ret = fac[N + K - 1] * mod_rev(fac[N], MOD) % MOD;
  return ret * mod_rev(fac[K - 1], MOD) % MOD;
}

// N 個を K グループに分割する
ll split_paterns_(ll N, ll K) {
  if (N == K) return 1;
  N -= K - 1;
  if (N < 0) return 0;
  // N 個の玉と K 個の棒を並べる
  ll tmp = fac[N + K] * mod_rev(fac[N], MOD) % MOD;
  return tmp * mod_rev(fac[K], MOD) % MOD;
}

int main() {
  fac[0] = 1;
  rep (i, 100000) {
    fac[i+1] = fac[i] * (i+1);
    fac[i+1] %= MOD;
  }

  int N, K;
  cin >> N >> K;

  rep (i, K) {
    ll x = i + 1;
    ll ret = split_paterns(K - x, x);
    ret *= split_paterns(N - K - (x - 1), x + 1);
    cout << ret % MOD << endl;
  }
}
