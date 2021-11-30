#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int a, b;
  cin >> a >> b;
  rep (i, 100) {
    if (i * a - i + 1 >= b) {
      cout << i << endl;
      return 0;
    }
  }
}
