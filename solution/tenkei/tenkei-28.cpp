#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const long long INF = 1e18;

int main() {
  int N; cin >> N;
  vector<vector<int>> table(1004, vector<int>(1004, 0));

  rep(i, N) {
    // (a, b) (c, d)
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    table[a][b] += 1;
    table[a][d] -= 1;
    table[c][b] -= 1;
    table[c][d] += 1;
  }

  rep(i, 1003) {
    rep(j, 1003) {
      table[i+1][j] += table[i][j];
    }
  }

  rep(i, 1003) {
    rep(j, 1003) {
      table[i][j+1] += table[i][j];
    }
  }

  vector<int> cnt(N+1, 0);
  rep(i, 1003) {
    rep(j, 1003) {
      cnt[table[i][j]] += 1;
    }
  }

  for (int i = 1; i < N+1; i++) {
    cout << cnt[i] << endl;
  }
}
