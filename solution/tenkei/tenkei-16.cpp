#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  ll a, b, c;
  cin >> a >> b >> c;

  int res = 100000;
  rep(i, 10000) {
    rep(j, i+1) {
      ll cnt = a * j + (b * (i - j));
      if (cnt <= N && (N - cnt) % c == 0) {
        res = min(res, (int)(i + (N - cnt) / c));
      }
    }
  }
  cout << res << endl;
}
