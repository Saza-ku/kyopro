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
  map<ll, int> m;

  rep (i, N) {
    ll v = i - a[i];
    if (!m.count(v)) m[v] = 1;
    else m[v]++;
  }
  ll res = 0;
  rep (i, N) {
    m[i - a[i]]--;
    if (m.count(i + a[i])) {
      res += m[i + a[i]];
    }
  }

  cout << res << endl;
}
