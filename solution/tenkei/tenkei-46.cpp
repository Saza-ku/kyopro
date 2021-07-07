#include <bits/stdc++.h>
using namespace std;

const int mod = 46;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

void input(vector<int> &a, int N) {
  rep(i, N) {
    int x;
    cin >> x;
    x %= mod;
    a[x]++;
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> a(mod, 0), b(mod, 0), c(mod, 0);
  input(a, N);
  input(b, N);
  input(c, N);

  ll res = 0;

  rep(i, mod) {
    rep(j, mod) {
      int k = mod * 2 - i - j;
      k %= mod;
      res += (ll)a[i] * b[j] * c[k];
    }
  }

  cout << res << endl;
}