#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

ll comb (int n, int r) {
  ll ret = 1;
  for (int i = 0; i < r; i++) {
    ret *= n - i;
    ret /= i + 1;
  }
  return ret;
}

int main() {
  int l;
  cin >> l;

  ll res = 0;
  int x = 11;
  int y = l - 12;
  cout << comb(x + y, x) << endl;
}
