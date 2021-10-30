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
  ll target = 0;
  vector<ll> points(N);
  rep (i, N) {
    ll ao, taka;
    cin >> ao >> taka;
    target += ao;
    points[i] = 2 * ao + taka;
  }

  sort(points.rbegin(), points.rend());
  ll point = 0;
  rep (i, N) {
    if (target < point) {
      cout << i << endl;
      return 0;
    }
    point += points[i];
  }
  cout << N << endl;
}
