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
  vector<int> table(N, 0);
  for (int i = 0; i < N-1; i++) {
    if (a[i] >= a[i+1]) {
      table[i+1] = table[i] + 1;
    }
  }
  int res = 0;
  rep (i, N) {
    res = max(res, table[i]);
  }
  cout << res << endl;
}
