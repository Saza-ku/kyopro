#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int x, y;
  cin >> x >> y;
  int a = min(x, y);
  int b = max(x, y);
  if (b < a + 3) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
