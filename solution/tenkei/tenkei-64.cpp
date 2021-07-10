#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i = 0; i < N; i++)

using ll = long long;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<ll> a(N), b(N-1);
  rep(i, N) cin >> a[i];
  rep(i, N-1) {
    b[i] = a[i+1] - a[i];
  }

  ll res = 0;

  rep(i, N-1) {
    res += abs(b[i]);
  }

  rep(i, Q) {
    int l, r, v;
    cin >> l >> r >> v;
    l--; r--;
    if (l != 0) {
      res -= abs(b[l-1]);
      b[l-1] += v;
      res += abs(b[l-1]);
    }
    if (r != N-1) {
      res -= abs(b[r]);
      b[r] -= v;
      res += abs(b[r]);
    }
    cout << res << endl;
  }
}