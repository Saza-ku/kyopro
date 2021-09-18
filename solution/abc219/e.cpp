#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const long long INF = 1e18;

bool bfs(int table[4][4], int sx, int sy) {
  bool reached[4][4];

  rep(i, 4) rep(j, 4) reached[i][j] = false;

  queue<pair<int, int>> q;
  q.push(mkp(sx, sy));
  while(!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();

    reached[x][y] = true;

    int nx, ny;
    nx = x; ny = y + 1;
    if (0 <= nx && nx < 4 && 0 <= ny && ny < 4
      && table[nx][ny] && !reached[nx][ny]) {
        q.push(mkp(nx, ny));
    }
    nx = x; ny = y - 1;
    if (0 <= nx && nx < 4 && 0 <= ny && ny < 4
      && table[nx][ny] && !reached[nx][ny]) {
        q.push(mkp(nx, ny));
    }
    nx = x - 1; ny = y;
    if (0 <= nx && nx < 4 && 0 <= ny && ny < 4
      && table[nx][ny] && !reached[nx][ny]) {
        q.push(mkp(nx, ny));
    }
    nx = x + 1; ny = y;
    if (0 <= nx && nx < 4 && 0 <= ny && ny < 4
      && table[nx][ny] && !reached[nx][ny]) {
        q.push(mkp(nx, ny));
    }
  }

  rep(i, 4) {
    rep(j, 4) {
      if (table[i][j] == 1 && !reached[i][j]) {
        return false;
      }
    }
  }

  q.push(mkp(sx, sy));
  while(!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();

    reached[x][y] = true;

    int nx, ny;
    nx = x; ny = y + 1;
    if (0 <= nx && nx < 4 && 0 <= ny && ny < 4
      && !table[nx][ny] && !reached[nx][ny]) {
        q.push(mkp(nx, ny));
    }
    nx = x; ny = y - 1;
    if (0 <= nx && nx < 4 && 0 <= ny && ny < 4
      && !table[nx][ny] && !reached[nx][ny]) {
        q.push(mkp(nx, ny));
    }
    nx = x - 1; ny = y;
    if (0 <= nx && nx < 4 && 0 <= ny && ny < 4
      && !table[nx][ny] && !reached[nx][ny]) {
        q.push(mkp(nx, ny));
    }
    nx = x + 1; ny = y;
    if (0 <= nx && nx < 4 && 0 <= ny && ny < 4
      && !table[nx][ny] && !reached[nx][ny]) {
        q.push(mkp(nx, ny));
    }
  }

  rep(i, 4) {
    rep(j, 4) {
      if (!reached[i][j]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int table[4][4];
  int vils[4][4];
  rep(i, 4) {
    rep(j, 4) {
      cin >> vils[i][j];
    }
  }

  int res = 0;
  rep (bit, 1 << 16) {
      bool ok = true;
      // table 作る
      int sx = 0, sy = 0;
      rep (x, 4) {
        rep (y, 4) {
          if ((bit >> y*4) & (1 << x)) {
            table[x][y] = 1;
            sx = x;
            sy = y;
          }
          else table[x][y] = 0;
          // 村を守っていないものはここで弾く
          if (vils[x][y] == 1 && table[x][y] != 1) {
            ok = false;
          }
        }
      }
      // 繋がってるか判定
      ok = ok && bfs(table, sx, sy);

      if (ok) res++;
    
  }
  cout << res << endl;
}
