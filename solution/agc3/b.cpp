#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  ll res = 0;
  vector<int> a(N);
  rep (i, N) cin >> a[i];
  rep (i, N) {
    res += a[i] / 2;
    a[i] %= 2;
    if (i < N - 1 && a[i] > 0 && a[i+1] > 0) {
      res++;
      a[i+1]--;
    }
  }

  cout << res << endl;
}
