#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd (ll x, ll y) {
  ll a = max(x, y);
  ll b = min(x, y);

  if (a % b == 0) return b;

  ll r = a % b;
  return gcd(b, r);
}

int main() {
  ll a, b;
  cin >> a >> b;

  ll d = gcd(a, b);

  ll p = a / d;
  ll q = b;

  if (p <= ll(1e18) / q) {
    cout << p * q << endl;
    return 0;
  }

  cout << "Large" << endl;
}
