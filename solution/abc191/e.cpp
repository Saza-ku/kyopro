#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;


struct edge {
  int to;
  int cost;
};

// g: グラフの隣接リスト, N: 頂点数, M: 辺数, s: 始点
vector<int> dfs(vector<vector<edge>> &g, int N, int M, int s) {
  vector<int> ret(N, INF);
  vector<bool> seen(N, false);
  priority_queue<pair<int, int>> q;
  q.push(mkp(0, s));

  while (!q.empty()) {
    int d, u;
    tie(d, u) = q.top();
    q.pop();
    ret[u] = d;
    seen[u] = true;

    for (auto v : g[u]) {
      if (seen[v.to]) continue;
      if (d + v.cost > ret[v.to]) continue;
      ret[v.to] = d + v.cost;
      q.push(mkp(ret[v.to], v.to));
    }
  }

  return ret;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<edge>> g(N);
  vector<vector<edge>> rg(N);
  vector<int> roop(N, INF);
  rep (i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    if (a == b) {
      roop[a] = min(roop[a], c);
      continue;
    }

    g[a].push_back({b, c});
    rg[b].push_back({a, c});
  }

  rep (i, N) {
    vector<int> cost_to = dfs(g, N, M, i);
    vector<int> cost_from = dfs(rg, N, M, i);

    int cost = INF;
    rep (j, N) {
      int to, from;
      to = cost_to[j];
      from = cost_from[j];
      if (to == 0) continue;
      cost = min(cost, to + from);
    }
    int res = min(roop[i], cost);
    if (res != INF) cout << res << endl;
    else cout << -1 << endl;
  }
}
