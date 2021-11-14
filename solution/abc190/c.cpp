#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> constraints(M);
  rep (i, M) {
    int x, y;
    cin >> x >> y;
    constraints[i].first = x;
    constraints[i].second = y;
  }

  int K;
  cin >> K;
  vector<pair<int, int>> c(K);
  rep (i, K) {
    int x, y;
    cin >> x >> y;
    c[i].first = x;
    c[i].second = y;
  }

  ll res = 0;
  rep (bit, 1<<K) {
    ll cnt = 0;
    vector<bool> table(N, false);
    rep (i, K) {
      int x;
      if (bit & 1<<i) x = c[i].first;
      else x = c[i].second;
      table[x] = true;
    }
    rep (i, M) {
      int x, y;
      tie(x, y) = constraints[i];
      if (table[x] && table[y]) cnt++;
    }

    res = max(res, cnt);
  }

  cout << res << endl;
}
