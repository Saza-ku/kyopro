#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i = 0; i < N; i++)
using ll = long long;

int main() {
  int N;
  cin >> N;

  long long res = 0;
  ll a, b;
  rep(i, N) {
    ll x, y;
    cin >> x >> y;
    if (i == 0) {
      a = x;
      b = y;
      continue;
    }

    res += abs(x - a) + abs(y - b);
  }

  cout << res << endl;
}