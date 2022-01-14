#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

struct data {
  ll cost;
  ll want;
  ll subst;
};

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> a(N);
  rep (i, N) {
    cin >> a[i];
  }

  ll res = 0;
  priority_queue<pair<ll, ll>> q;
  for (ll bit = 1; bit <= (ll)1e12; bit <<= 1) {
    ll cnt = 0;
    rep (i, N) {
      if (bit & a[i]) {
        cnt++;
      }
    }

    if (cnt <= N / 2) {
      q.push(mkp((N - 2 * cnt) * bit, bit));
    }
    res += cnt * bit;
  }

  while(!q.empty()) {
    ll x, cost;
    tie(x, cost) = q.top();
    q.pop();

    if (K - cost >= 0) {
      res += x;
      K -= cost;
    }
  }

  cout << res << endl;
}
