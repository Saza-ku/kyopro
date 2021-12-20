#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  ll N;
  cin >> N;
  map<ll, ll> m;
  rep (i, N) {
    ll a;
    cin >> a;
    if (m.count(a)) {
      m[a]++;
    }
    else {
      m[a] = 1;
    }
  }

  ll res = N * (N - 1) / 2;
  for (auto p : m) {
    ll a, cnt;
    tie(a, cnt) = p;
    res -= cnt * (cnt - 1) / 2;
  }

  cout << res << endl;
}
