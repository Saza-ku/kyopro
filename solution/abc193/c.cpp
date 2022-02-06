#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair
#define pb push_back

using ll = long long;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  ll N;
  cin >> N;

  set<ll> s;
  ll res = N;

  for (ll x = 2; x < 100000 + 3; x++) {
    ll tmp = x;
    for (ll a = 2; a < 100000 + 3; a++) {
      if (tmp > INFL / x) {
        break;
      }
      tmp *= x;
      if (tmp > N) {
        break;
      }
      if (!s.count(tmp)) {
        res--;
        s.insert(tmp);
      }
    }
  }

  cout << res << endl;
}
