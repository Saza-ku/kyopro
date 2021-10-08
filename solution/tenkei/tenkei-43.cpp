#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int H, W;
  cin >> H >> W;
  int xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  xs--; ys--; xt--; yt--;

  vector<vector<char>> grid(H, vector<char>(W));

  rep(i, H) rep(j, W) cin >> grid[i][j];

  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

  vector<vector<int>> d(H, vector<int>(W));
  vector<vector<bool>> reached(H, vector<bool>(W));
  rep(i, H) {
    rep(j, W) {
      d[i][j] = INF;
      reached[i][j] = false;
    }
  }

  q.push(mkp(-1, mkp(xs, ys)));
  while(!q.empty()) {
    int min_d;
    pair<int, int> p;
    tie(min_d, p) = q.top();
    int x, y;
    tie(x, y) = p;
    q.pop();

    d[x][y] = min_d;
    reached[x][y] = true;

    if (x == xt && y == yt) break;

    for (int i = 1; x + i < H; i++) {
      // (x, y) -> (nx, ny)
      int nx = x + i, ny = y;
      if (grid[nx][ny] == '#') break;
      if (reached[nx][ny]) continue;
      if (d[nx][ny] <= min_d + 1) continue;
      pair<int, int> u = mkp(nx, ny);
      q.push(mkp(min_d + 1, u));
      d[nx][ny] = min_d + 1;
    }
    for (int i = 1; x - i >= 0; i++) {
      // (x, y) -> (nx, ny)
      int nx = x - i, ny = y;
      if (grid[nx][ny] == '#') break;
      if (reached[nx][ny]) continue;
      if (d[nx][ny] <= min_d + 1) continue;
      pair<int, int> u = mkp(nx, ny);
      q.push(mkp(min_d + 1, u));
      d[nx][ny] = min_d + 1;
    }
    for (int i = 1; y + i < W; i++) {
      // (x, y) -> (nx, ny)
      int nx = x , ny = y + i;
      if (grid[nx][ny] == '#') break;
      if (reached[nx][ny]) continue;
      if (d[nx][ny] <= min_d + 1) continue;
      pair<int, int> u = mkp(nx, ny);
      q.push(mkp(min_d + 1, u));
      d[nx][ny] = min_d + 1;
    }
    for (int i = 1; y - i >= 0; i++) {
      // (x, y) -> (nx, ny)
      int nx = x, ny = y - i;
      if (grid[nx][ny] == '#') break;
      if (reached[nx][ny]) continue;
      if (d[nx][ny] <= min_d + 1) continue;
      pair<int, int> u = mkp(nx, ny);
      q.push(mkp(min_d + 1, u));
      d[nx][ny] = min_d + 1;
    }
  }

  cout << d[xt][yt] << endl;
}
