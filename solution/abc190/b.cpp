#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N, S, D;
  cin >> N >> S >> D;
  rep (i, N) {
    int x, y;
    cin >> x >> y;
    if (x < S && y > D) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
