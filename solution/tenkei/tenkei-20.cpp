#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll m = 1;
  rep (i, b) {
    m *= c;
  }
  if (a < m) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
