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
  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  vector<int> b(M);
  rep(i, N) cin >> a[i];
  rep(i, M) cin >> b[i];

  rep(j, M) {
    bool found = false;
    rep(i, N) {
      if (a[i] == b[j]) {
        found = true;
        a[i] = -1;
        break;
      }
    }
    if (!found) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
