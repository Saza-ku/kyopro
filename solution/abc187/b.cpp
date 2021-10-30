#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<P> p(N);
  rep (i, N) cin >> p[i].first >> p[i].second;
  int res = 0;
  rep (i, N) {
    for (int j = i + 1; j < N; j++) {
      int a, b, c, d;
      tie(a, b) = p[i];
      tie(c, d) = p[j];
      if (abs(d - b) <= abs(c - a)) {
        res++;
      }
    }
  }
  cout << res << endl;
}
