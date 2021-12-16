#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int N;
  string s1, s2;
  cin >> N;
  cin >> s1 >> s2;
  ll res = 1;
  int used_color = 0;
  rep (i, N) {
    if (s1[i] == s2[i]) {
      res *= (3 - used_color);
      used_color = 1;
    }
    else {
      if (used_color == 0) {
        res *= 6;
      }
      else if (used_color == 1) {
        res *= 2;
      }
      else {
        res *= 3;
      }
      used_color = 2;
      i++;
    }
    res %= MOD;
  }

  cout << res << endl;
}
