#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> v(M+1);
  int tmp = 0;
  vector<int> a(M);
  int min_elem = INF;
  rep (i, M) cin >> a[i];
  sort(a.begin(), a.end());
  rep (i, M) {
    if (a[i] == tmp) {
      v[i] = 0;
      continue;
    }
    v[i] = a[i] - tmp - 1;
    tmp = a[i];
  }
  v[M] = max(N - tmp, 0);

  rep (i, M+1) {
    // cout << v[i] << endl;
    if (v[i] != 0) {
      min_elem = min(min_elem, v[i]);
    }
  }

  int res = 0;
  rep (i, M+1) {
    res += (v[i] + min_elem - 1) / min_elem;
  }

  cout << res << endl;
}
