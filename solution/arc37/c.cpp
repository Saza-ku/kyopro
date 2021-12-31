#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

ll binary_search(ll ng, ll ok, function<bool(ll)> is_ok) {
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (is_ok(mid)) {
      ok = mid;
    }
    else {
      ng = mid;
    }
  }
  return ok;
}

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> a(N), b(N);
  rep (i, N) cin >> a[i];
  rep (i, N) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll res = binary_search(0, INFL + 10, [&](ll x) {
    ll cnt = 0;
    rep (i, N) {
      ll y = x / a[i];
      auto it = upper_bound(b.begin(), b.end(), y);
      cnt += N - distance(it, b.end());
    }
    if (cnt >= K) return true;
    return false;
  });

  cout << res << endl;
}
