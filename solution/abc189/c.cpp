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
  vector<int> a(N);
  rep (i, N) cin >> a[i];
  vector<vector<int>> table(N, vector<int>(N));

  rep (i, N) {
    table[i][i] = a[i];
    for (int j = i + 1; j < N; j++) {
      table[i][j] = min(table[i][j-1], a[j]);
    }
  }

  int res = 0;
  rep (i, N) {
    for (int j = i; j < N; j++) {
      res = max(res, table[i][j] * (j - i + 1));
    }
  }

  cout << res << endl;
}
