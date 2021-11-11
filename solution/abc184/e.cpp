#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
using P = pair<int, int>;
const int INF = -1;
const ll INFL = 1e18;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  vector<vector<P>> table(26);
  P s, t;
  rep (i, H) {
    rep (j, W) {
      cin >> grid[i][j];
      if ('a' <= grid[i][j] && grid[i][j] <= 'z') {
        table[grid[i][j] - 'a'].push_back(mkp(i, j));
      }
      if (grid[i][j] == 'S') {
        s = mkp(i, j);
      }
      if (grid[i][j] == 'G') {
        t = mkp(i, j);
      }
    }
  }

  queue<P> q;
  q.push(s);
  vector<vector<int>> d(H, vector<int>(W, INF));
  vector<bool> done(26);
  d[s.first][s.second] = 0;
  while (!q.empty()) {
    P u = q.front(); q.pop();
    if (u == t) break;

    if (u.first > 0 && d[u.first-1][u.second] == INF
        && grid[u.first-1][u.second] != '#') {
      d[u.first-1][u.second] = d[u.first][u.second] + 1;
      q.push(mkp(u.first-1, u.second));
    }
    if (u.first < H-1 && d[u.first+1][u.second] == INF
        && grid[u.first+1][u.second] != '#') {
      d[u.first+1][u.second] = d[u.first][u.second] + 1;
      q.push(mkp(u.first+1, u.second));
    }
    if (u.second > 0 && d[u.first][u.second-1] == INF
        && grid[u.first][u.second-1] != '#') {
      d[u.first][u.second-1] = d[u.first][u.second] + 1;
      q.push(mkp(u.first, u.second-1));
    }
    if (u.second < W-1 && d[u.first][u.second+1] == INF
        && grid[u.first][u.second+1] != '#') {
      d[u.first][u.second+1] = d[u.first][u.second] + 1;
      q.push(mkp(u.first, u.second+1));
    }

    int x = grid[u.first][u.second] - 'a';
    if (0 <= x && x < 26 && !done[x]) {
      done[x] = true;
      for (auto v : table[x]) {
        if (d[v.first][v.second] == INF) {
          d[v.first][v.second] = d[u.first][u.second] + 1;
          q.push(v);
        }
      }
    }
  }

  cout << d[t.first][t.second] << endl;
}
