#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  rep (i, N) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  rep (i, Q) {
    int x;
    cin >> x;
    auto iter = lower_bound(a.begin(), a.end(), x);
    cout << distance(iter, a.end()) << endl;
  }
}
