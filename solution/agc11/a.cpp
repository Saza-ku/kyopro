#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  ll N, C, K;
  cin >> N >> C >> K;
  vector<ll> T(N);
  rep (i, N) {
    cin >> T[i];
  }

  sort (T.begin(), T.end());

  ll tmp = 0;
  ll now = -INFL;
  ll res = 0;

  rep (i, N) {
    ll t = T[i];
    if (now + K < t || C <= tmp) {
      now = t;
      tmp = 1;
      res++;
    }
    else {
      tmp++;
    }
  }

  cout << res << endl;
}
