#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
  ll N; cin >> N;

  ll cnt = 0;
  for (ll i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      N /= i;
      cnt++;
    }
  }
  if (N != 1) cnt++;

  ll pow2 = 1;
  ll res = 0;
  while (pow2 < cnt) {
    pow2 *= 2;
    res++;
  }

  cout << res << endl;
}