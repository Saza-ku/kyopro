#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N;
  cin >> N;

  vector<vector<char>> res(N, vector<char>(N));

  rep (i, N) {
    rep (j, i) {
      if (i % 2 == 0) {
        res[i][j] = '.';
      }
      else {
        res[i][j] = '#';
      }
    }

    rep (j, i) {
      if (i % 2 == 0) {
        res[j][i] = '#';
      }
      else {
        res[j][i] = '.';
      }
    }

    res[i][i] = '.';
  }

  rep (i, N) {
    rep (j, N) {
      cout << res[i][j];
    }
    cout << endl;
  }
}
