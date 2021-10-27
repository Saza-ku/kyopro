#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N, M, T;
  cin >> N >> M >> T;

  int now = 0;
  int max_N = N;

  rep (i, M) {
    int a, b;
    cin >> a >> b;
    N -= a - now;
    if (N <= 0) {
      cout << "No" << endl;
      return 0;
    }
    N = min(max_N, N + b - a);
    now = b;
  }

  N -= T - now;
  if (N <= 0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
