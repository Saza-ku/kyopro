#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N, T;
  cin >> N;
  vector<int> a(N);
  rep (i, N) cin >> a[i];
  cin >> T;

  sort(a.begin(), a.end());
  int res = 0;
  int now = -1;
  rep (i, N) {
    int x = a[i] / T;
    if (now != x) {
      res++;
      now = x;
    }
  }

  cout << res << endl;
}
