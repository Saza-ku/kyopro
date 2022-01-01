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
  for (ll mask = 1 << 30; mask > 0; mask >>= 1) {
    int cnt = 0;
    rep (i, N) {
      if ((res | mask) == ((res | mask) & a[i])) {
        cnt++;
      }
    }
    if (cnt > 1) res |= mask;
  }

  cout << 2 * res << endl;
}
