#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  ll N;
  cin >> N;
  rep (i, N + 1000) {
    if (i * (i + 1) >= 2 * N) {
      cout << i << endl;
      return 0;
    }
  }
}
