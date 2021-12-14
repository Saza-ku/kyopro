#include<bits/stdc++.h>
using namespace std;
#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int N, M;
vector<ll> a;
vector<vector<int>> g;
ll res = - INFL;
vector<ll> dp(300000 + 10, INFL);

int main() {
  cin >> N >> M;
  a.resize(N);
  rep (i, N) cin >> a[i];
  g.resize(N);
  rep (i, M) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
  }

  rep (u, N) {
    for (auto v : g[u]) {
      dp[v] = min(dp[v], min(dp[u], a[u]));
    }
  }

  rep (u, N) {
    res = max(res, a[u] - dp[u]);
  }

  cout << res << endl;
}
