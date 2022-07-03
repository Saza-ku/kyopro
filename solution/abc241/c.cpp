#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair
#define pb push_back

using ll = long long;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  vector<string> m(N);
  rep (i, N) cin >> m[i];

  rep (i, N) { rep (j, N) {
    if (i + 5 >= N) break;
    int count = 0;

    rep (k, 6) {
      if (m[i][j+k] == '#') count++;
    }
    if (count >= 4) {
      cout << "Yes" << endl;
      return 0;
    }

    count = 0;
    rep (k, 6) {
      if (m[i+k][j] == '#') count++;
    }
    if (count >= 4) {
      cout << "Yes" << endl;
      return 0;
    }

    count = 0;
    rep (k, 6) {
      if (m[i+k][j+k] == '#') count++;
    }
    if (count >= 4) {
      cout << "Yes" << endl;
      return 0;
    }


  }}
  cout << "No" << endl;
}
