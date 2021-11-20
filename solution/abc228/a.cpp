#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int s, t, x;
  cin >> s >> t >> x;
  if (t < s) t += 24;
  if (s <= x && x < t) {
    cout << "Yes" << endl;
    return 0;
  }
  x += 24;
  if (s <= x && x < t) {
    cout << "Yes" << endl;
    return 0;
  }
  else {
    cout << "No" << endl;
  }
}
