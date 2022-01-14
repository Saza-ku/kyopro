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
  set<int> s;
  rep (i, N) {
    int a;
    cin >> a;
    if (s.count(a)) {
      cout << "NO" << endl;
      return 0;
    }
    s.insert(a);
  }
  cout << "YES" << endl;
}
