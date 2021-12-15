#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

ll N, M;

long long repeat_squaring(long long x, long long n, long long mod) {
  x %= mod;
  if(n == 0) {
    return 1;
  }
  else if(n % 2 == 0) {
    long long t = repeat_squaring(x, n / 2, mod);
    return t * t % mod;
  }
  else {
    return x * repeat_squaring(x, n - 1, mod) % mod;
  }
}

int main() {
  cin >> N >> M;

  // X := 10^N mod M^2
  ll X = repeat_squaring(10, N, M*M);

  rep (i, M) {
    rep (j, M) {
      if ((X - M * i - j) % (M * M) == 0) {
        cout << i << endl;
        return 0;
      }
    }
  }
}
