#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int>> t(N, vector<int>(N));
  rep (i, N) rep (j, N) cin >> t[i][j];

  vector<int> v(N);
  rep(i, N) v[i] = i;

  int res = 0;

  do {
    if (v[0] != 0) continue;
    int sum = 0;
    for (int i = 0; i < N; i++) {
      // x -> y
      int x, y;
      x = v[i];
      y = v[(i+1) % N];
      sum += t[x][y];
    }
    if (sum == K) res++;
  } while (next_permutation(v.begin(), v.end()));

  cout << res << endl;
}
