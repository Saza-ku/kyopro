#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N; cin >> N;
  vector<int> a(N);
  rep(i, N) {
    cin >> a[i];
  }
  int res;
  int max_count = -1;

  rep (i, 1001) {
    if (i == 0 || i == 1) continue;
    int m = 0;
    rep(j, N) {
      if (a[j] % i == 0) m++;
    }
    if (max_count < m) {
      res = i;
      max_count = m;
    }
  }

  cout << res << endl;
}
