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
  string s;
  cin >> s;
  rep (i, N) {
    if (s[i] == 'o') X++;
    else {
      X = max(0, X-1);
    }
  }

  cout << X << endl;
}
