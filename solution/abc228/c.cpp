#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> p(N, 0);
  rep (i, N) {
    int a, b, c;
    cin >> a >> b >> c;
    p[i] = a + b + c;
  }
  vector<int> table = p;
  sort(table.begin(), table.end());

  rep (i, N) {
    int x = p[i] + 300;
    auto iter = upper_bound(table.begin(), table.end(), x);
    int rank = distance(iter, table.end()) + 1;
    if (rank <= K) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}
