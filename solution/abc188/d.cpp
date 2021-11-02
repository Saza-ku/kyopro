#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  ll N, C;
  cin >> N >> C;
  vector<pair<ll, ll>> events(2*N);
  rep (i, N) {
    ll a, b, c;
    cin >> a >> b >> c;
    events[i] = mkp(a, c);
    events[i+N] = mkp(b, -c);
  }
  sort(events.begin(), events.end());

  ll day = 0;
  ll fee = 0;
  ll res = 0;
  rep (i, 2*N) {
    if (events[i].second > 0) {
      fee += events[i].second;
    }
    res += (events[i].first - day) * min(fee, C);
    day = events[i].first;
    if (events[i].second < 0) {
      fee += events[i].second;
    }
  }
  cout << res << endl;
}
