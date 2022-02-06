#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair
#define pb push_back

using ll = long long;

const int INF = 1e9 + 1;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  int res = INF;
  rep (i, N) {
    int a, p, x;
    cin >> a >> p >> x;
    if (x - a > 0) {
      res = min(res, p);
    }
  }
  cout << (res == INF ? -1 : res) << endl;
}
