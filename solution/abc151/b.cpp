#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int N, M, K;
  cin >> N >> K >> M;
  int s = 0;
  vector<int> a(N);
  rep (i, N-1) cin >> a[i];
  rep (i, N-1) s += a[i];
  int x = M * N - s;
  if (x > K) cout << -1 << endl;
  else cout << max(0, x) << endl;
}
