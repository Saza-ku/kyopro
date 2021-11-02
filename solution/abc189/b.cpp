#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N, X;
  cin >> N >> X;
  X *= 100;
  int s = 0;
  rep (i, N) {
    int v, p;
    cin >> v >> p;
    s += v * p;
    if (X < s) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
