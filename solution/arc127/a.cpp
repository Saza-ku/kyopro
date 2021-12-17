#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  ll N;
  cin >> N;

  ll res = 0;
  ll prefix = 0;
  // (i+1) 個の 1 が連続する
  for (int i = 0; i < 16; i++) {
    prefix += pow(10, i);
    // (j+1) 桁あるやつ
    for (int j = 0; j < 16 - i; j++) {
      ll bottom = prefix * pow(10, j);
      ll top = (prefix + 1) * pow(10, j);
      res += max(0LL, min(N+1, top) - bottom);
    }
  }

  cout << res << endl;
}
