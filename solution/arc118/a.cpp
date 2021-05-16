#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

int t;

ll f(ll x) {
    return (100 + t) * x / 100;
}

ll n(ll x) {
    return f(x) - x;
}

int main() {
  cin >> t;
  ll N; cin >> N;

  ll l = 0, r = 1e11;

  while(abs(l - r) > 1) {
      ll mid = (l+r) / 2;
      if(n(mid) < N) l = mid;
      else r = mid;
  }

  //cout << r << endl;
  cout << f(r) - 1 << endl;
}
