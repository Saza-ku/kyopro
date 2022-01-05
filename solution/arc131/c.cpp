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
  cin >> N;
  vector<int> a(N);
  rep (i, N) cin >> a[i];

  int s = 0;
  rep (i, N) s ^= a[i];

  if (N % 2 == 1) {
    cout << "Win" << endl;
  }
  else {
    rep (i, N) {
      if ((s ^ a[i]) == 0) {
        cout << "Win" << endl;
        return 0;
      }
    }
    cout << "Lose" << endl;
  }
}
