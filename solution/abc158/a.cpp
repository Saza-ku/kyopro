#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  char x = s[0];
  rep (i, 3) {
    if (s[i] != x) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
