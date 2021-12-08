#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int v, t, s, d;
  cin >> v >> t >> s >> d;
  if (v * t <= d && d <= v * s) cout << "No" << endl;
  else cout << "Yes" << endl;
}
