#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N, X;
  cin >> N >> X;
  X--;

  int x = X;
  vector<int> a(N);
  rep (i, N) {
    cin >> a[i];
    a[i]--;
  }
  vector<bool> table(N, false);
  int res = 1;
  rep (i, N) {
    table[x] = true;
    if (!table[a[x]]) {
      res++;
      x = a[x];
    }
    else {
      break;
    }
  }
  cout << res << endl;
}
