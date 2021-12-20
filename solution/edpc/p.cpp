#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

vector<vector<int>> g;
queue<pair<int, int>> q;
vector<vector<ll>> dp;

void dfs(int u, int from) {
  dp[u][0] = 1;
  dp[u][1] = 1;

  for (int v : g[u]) {
    if (v == from) continue;
    dfs(v, u);
    dp[u][0] *= dp[v][0] + dp[v][1];
    dp[u][1] *= dp[v][0];
    dp[u][0] %= MOD;
    dp[u][1] %= MOD;
  }
}

int main() {
  int N;
  cin >> N;
  g.resize(N);
  dp.resize(N, vector<ll>(2));
  rep (i, N-1) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(0, -1);

  cout << (dp[0][0] + dp[0][1]) % MOD << endl;
}
