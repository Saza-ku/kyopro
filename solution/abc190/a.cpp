#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a < b) {
    cout << "Aoki" << endl;
  }
  else if (a > b) {
    cout << "Takahashi" << endl;
  }
  else {
    if (c == 0) {
      cout << "Aoki" << endl;
    }
    else {
      cout << "Takahashi" << endl;
    }
  }
}
