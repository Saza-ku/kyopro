#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int res = 0;
  string s, t;
  cin >> s >> t;
  rep (i, 3) {
    if (s[i] == t[i]) res++;
  }

  cout << res << endl;
}
