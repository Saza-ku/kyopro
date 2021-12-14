#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 9e18;

int main() {
  ll N, X;
  cin >> N >> X;
  ll first_X = X;
  vector<ll> a(N, INFL);
  ll cnt = 0;
  ll res = INFL;
  rep (i, N) {
    cnt = 0;
    X = first_X;
    cin >> a[i];

    while (X > 0) {
      auto iter = upper_bound(a.begin(), a.end(), X);
      iter--;
      ll x = *iter;
      cnt += X / x;
      X %= x;
    }


    res = min(cnt, res);
    cout << i << " " << res << endl;
  }

  for (int i = 0; i < N; i++) {
  auto it = upper_bound(a.begin(), a.end(), first_X);
    rep (j, i) it++;
    if (it == a.end()) {
      cout << res << endl;
      return 0;
    }

    X = *it - first_X;

    cnt = i + 1;
    while (X > 0) {
      auto iter = upper_bound(a.begin(), a.end(), X);
      iter--;
      ll x = *iter;
      cnt += X / x;
      X %= x;
    }
    res = min(cnt, res);
    cout << i << " " << res << " " << distance(it, a.end()) << endl;
  }


  cout << res << endl;
}
