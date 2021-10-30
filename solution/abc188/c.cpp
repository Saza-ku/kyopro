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
  vector<pair<ll, int>> a(1<<N);
  rep (i, 1<<N) {
    cin >> a[i].first;
    a[i].second = i;
  }

  ll x = N;
  rep (i, N-1) {
    vector<pair<ll, int>> b(0);
    for (int j = 0; j < 1<<x; j+=2) {
      b.push_back(max(a[j], a[j+1]));
    }
    a = b;
    x--;
  }
  cout << min(a[0], a[1]).second + 1 << endl;
}
