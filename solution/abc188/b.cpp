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
  vector<ll> a(N), b(N);
  rep (i, N) {
    cin >> a[i];
  }
  rep (i, N) cin >> b[i];

  ll res = 0;
  rep (i, N) {
    res += a[i] * b[i];
  }
  if (res == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}
