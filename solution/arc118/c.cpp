#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

ll gcd(ll m, ll n){
  ll a = max(m, n);
  ll b = min(m, n);
  ll r = a % b;

  while(r != 0){
    a = b;
    b = r;
    r = a % b;
  }

  return b;
}

int main() {
  int N;
  cin >> N;

  if (N == 3) {
    cout << 6 << endl << 10 << endl << 15 << endl;
    return 0;
  }

  for (int i = 1; i <= 10000; i++) {
    if (i % 6 == 0 || i % 10 == 0 || i % 15 == 0) {
      cout << i << endl;
      N--;
    }
    if (N == 0) break;
  }
}

/*
int main() {
  for (int i = 2; i < 100; i++) {
    for (int j = i + 1; j < 100; j++) {
      for(int k = j + 1; k < 100; k++) {
        for (int l = k + 1; l < 100; l++) {
          bool ok = gcd(i, gcd(j, gcd(k, l))) == 1 && gcd(i, j) != 1 && gcd(j, k) != 1 && gcd(k, i) != 1 && gcd(i, l) != 1 && gcd(j, l) != 1 && gcd(k, l) != 1;
          if (ok) {
            cout << i << " " << j << " " << k << " " << l << " " << endl;
            return 0;
          }
        }
      }
    }
  }
}
*/
