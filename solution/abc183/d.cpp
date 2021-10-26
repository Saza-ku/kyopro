#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  ll N, W;
  cin >> N >> W;
  vector<ll> table(2e5 + 10);
  rep (i, N) {
    ll s, t, w;
    cin >> s >> t >> w;
    table[s] += w;
    table[t] -= w;
  }
  rep (i, 2e5 + 10) {
    table[i+1] += table[i];
  }
  rep (i, 2e5 + 10) {
    if (table[i] > W) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
