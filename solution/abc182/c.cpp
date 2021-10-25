#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  string s;
  cin >> s;
  int N = s.size();

  int res = -1;

  rep(bit, 1 << N) {
    if (bit == 0) continue;
    int sum = 0;
    int cnt = 0;
    rep(i, N) {
      if (bit & 1 << i) {
        sum += s[i] - '0';
        cnt++;
      }
    }
    if (sum % 3 == 0) {
      res = max(res, cnt);
    }
  }

  if (res == -1) cout << -1 << endl;
  else cout << N - res << endl;
}
