#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

bool done[5000][5000];
ll memo[5000][5000];
int H, W;
char grid[5000][5000];

ll dp(int i, int j) {
  if (done[i][j]) return memo[i][j];
  done[i][j] = true;

  int turn = (i + j) % 2;

  if (i == H - 1 && j == W - 1) return memo[i][j] = 0;

  if (turn == 0) {
    // takahashi
    memo[i][j] = -INF;
    if (i + 1 < H) memo[i][j] = max(memo[i][j], dp(i+1, j) + (grid[i+1][j] == '+' ? 1 : -1));
    if (j + 1 < W) memo[i][j] = max(memo[i][j], dp(i, j+1) + (grid[i][j+1] == '+' ? 1 : -1));
  }
  else {
    memo[i][j] = INF;
    if (i + 1 < H) memo[i][j] = min(memo[i][j], dp(i+1, j) - (grid[i+1][j] == '+' ? 1 : -1));
    if (j + 1 < W) memo[i][j] = min(memo[i][j], dp(i, j+1) - (grid[i][j+1] == '+' ? 1 : -1));
  }
  return memo[i][j];
}

int main() {
  cin >> H >> W;
  rep (i, H) rep (j, W) cin >> grid[i][j];

  ll res = dp(0, 0);

  if (res > 0) cout << "Takahashi" << endl;
  else if (res < 0) cout << "Aoki" << endl;
  else cout << "Draw" << endl;
}
