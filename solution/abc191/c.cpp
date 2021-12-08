#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

const int INF = 1e9;

bool is_block(char a) {
  return a == '#';
}

int angle_count(int i, int j, vector<vector<char>> a) {
  char ul, ur, ll, lr;
  ul = a[i][j];
  ur = a[i][j+1];
  ll = a[i+1][j];
  lr = a[i+1][j+1];

  int bit = 0;

  // 0  1
  // 2  3
  if (is_block(ul)) bit |= 1;
  if (is_block(ur)) bit |= 1 << 1;
  if (is_block(ll)) bit |= 1 << 2;
  if (is_block(lr)) bit |= 1 << 3;

  if (
    bit == (1 << 1 )||
    bit == (1 << 2 )||
    bit == (1 << 3 )||
    bit == (1 | 1 << 2 | 1 << 3 )||
    bit == (1 | 1 << 3 | 1 << 1 )||
    bit == (1 << 2 | 1 << 3 | 1 << 1 )||
    bit == (1 | 1 << 2 | 1 << 1) ||
        bit == (1)
  ) return 1;
  if (
    bit == (1 | 1 << 3 )||
    bit == (1 << 2 | 1 << 1 )) return 2;
  return 0;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  rep (i, H) rep (j, W) cin >> a[i][j];
  int res = 0;
  rep (i, H-1) {
    rep (j, W-1) {
      res += angle_count(i, j, a);
    }
  }

  cout << res << endl;
}
