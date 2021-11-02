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
    cin >> constraints[i].first >> constraints[i].second;
  }

  int K;
  cin >> K;
  vector<pair<int, int>> c(K);
  rep (i, K) cin >> c[i].first >> c[i].second;

  ll res = 0;
  rep (bit, 1<<K) {
    ll cnt = 0;
    rep (i, M) {
      int x;
      if (bit & 1<<i) x = c[i].first;
      else x = c[i].second;


    }
  }
}
