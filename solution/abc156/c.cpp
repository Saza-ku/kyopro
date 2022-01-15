#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;


vector<int> a;

ll f(int x) {
  int N = a.size();
  ll ret = 0;
  rep (i, N) {
    ret += (x - a[i]) * (x - a[i]);
  }
  return ret;
}

int main() {
  int N;
  cin >> N;
  a.resize(N);
  int s = 0;
  rep (i, N) {
    cin >> a[i];
    s += a[i];
  }

  ll res = INFL;

  int x = s / N;
  res = min(res, f(x));
  x = s / N + 1;
  res = min(res, f(x));

  cout << res << endl;
}
