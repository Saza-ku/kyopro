#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  string s, t;
  cin >> s >> t;
  int a = s[2] + s[1] + s[0] - 3 * '0';
  int b = t[2] + t[1] + t[0] - 3 * '0';
  cout << max(a, b) << endl;
}
