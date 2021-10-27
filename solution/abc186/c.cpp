#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

bool is_ok(int x) {
  int t = x;
  while (t) {
    if (t % 10 == 7) {
      return false;
    }
    t /= 10;
  }
  t = x;
  while (t) {
    if (t % 8 == 7) {
      return false;
    }
    t /= 8;
  }
  return true;

}

int main() {
  int N;
  cin >> N;

  int res = 0;
  for (int i = 1; i <= N; i++) {
    if (is_ok(i)) res++;
  }

  cout << res << endl;
}
