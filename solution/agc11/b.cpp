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
  vector<ll> a(N);
  rep (i, N) cin >> a[i];
  sort(a.begin(), a.end());

  ll s = 0;
  ll res = 0;
  rep (i, N-1) {
    s += a[i];
    if (s * 2 < a[i+1]) {
      res = 0;
    } else {
      res++;
    }
  }

  cout << res + 1 << endl;
}
