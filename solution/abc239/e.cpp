#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair
#define pb push_back

using ll = long long;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

vector<int> x;
void make_table(vector<vector<int>>& table, vector<vector<int>>& g, int u, int from) {
  vector<int> t;
  t.pb(x[u]);
  for (int v : g[u]) {
    if (v == from) continue;
    make_table(table, g, v, u);
    t.insert(t.end(), table[v].begin(), table[v].end());
  }
  sort(t.rbegin(), t.rend());
  for (int i = 0; i < 20; i++) {
    if (i == t.size()) break;
    table[u].pb(t[i]);
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  x.resize(N);
  rep (i, N) cin >> x[i];
  vector<vector<int>> g(N);
  rep (i, N-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  vector<vector<int>> table(N);
  make_table(table, g, 0, -1);

  rep (i, Q) {
    int u, k;
    cin >> u >> k;
    u--; k--;
    cout << table[u][k] << endl;
  }
}
