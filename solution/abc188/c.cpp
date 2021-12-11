#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N, C;
  cin >> N >> C;
  map<int, ll> events;
  for (int i = 0; i < N; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    if (events.count(a)) {
      events[a] += c;
    }
    else {
      events[a] = c;
    }

    if (events.count(b+1)) {
      events[b+1] -= c;
    }
    else {
      events[b+1] = -c;
    }
  }

  ll cost = 0;
  ll res = 0;
  ll day = 0;
  for (auto p : events) {
    int d, c;
    tie(d, c) = p;

    res += min((ll)C, cost) * (d - day);
    day = d;
    cost += c;
  }

  cout << res << endl;
}
