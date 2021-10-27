#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  rep (i, N) cin >> a[i];

  sort(a.begin(), a.end());

  vector<ll> s(N+1);
  s[0] = 0;
  rep (i, N) {
    s[i+1] = s[i] + a[i];
  }
  ll res = 0;
  rep (i, N) {
    res -= (N - i - 1) * a[i];
    res += s[N] - s[i+1];
  }

  cout << res << endl;
}
