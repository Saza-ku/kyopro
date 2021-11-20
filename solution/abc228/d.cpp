#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

ll func(ll v, ll x, vector<ll> &a, vector<ll> &f) {
  if (f[x] == -1) {
    a[x] = v;
    f[x] = x + 1;

    return x + 1;
  }

  f[x] = func(v, f[x], a, f);
  return f[x];
}

ll N, Q;

int main() {
  N = pow(2, 20);
  cin >> Q;
  vector<ll> a(N, -1);
  vector<ll> f(N, -1);

  rep (i, Q) {
    ll t, x;
    cin >> t >> x;
    ll v = x;
    x %= N;
    if (t == 2) {
      cout << a[x] << endl;
      continue;
    }

    func(v, x, a, f);
  }
}
