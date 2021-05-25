#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll N; cin >> N;
  ll b = 0;
  ll pow_b = 1;

  ll res = 1e18;
  while (pow_b <= N) {
    ll a = N / pow_b;
    ll c = N - pow_b * a;
    res = min(res, a + b + c);
    b++;
    pow_b *= 2;
  }
  cout << res << endl;
}