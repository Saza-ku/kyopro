#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair
#define pb push_back

using ll = long long;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;



int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll x = (a + c) / 2, y = (b + d) / 2;

  for (int i = -100; i < 100; i++) {
    for (int j = -100; j < 100; j++) {
      ll p = x + i, q = y + j;
      if (dist(p, q, a, b) == 5 && dist(p, q, c, d) == 5) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
