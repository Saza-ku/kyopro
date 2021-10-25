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
  ll res = -INFL;
  vector<ll> s(N);
  s[0] = a[0];
  vector<ll> m(N);
  rep (i, N) {
    if (i == 0) continue;
    s[i] = s[i-1] + a[i];
  }

  m[0] = max(0, a[0]);
  rep (i, N) {
    if (i == 0) continue;
    m[i] = max(m[i-1], s[i]);
  }

  ll tmp = 0;
  rep (i, N) {
    res = max(res, tmp + m[i]);
    tmp += s[i];
  }
  cout << res << endl;
}
