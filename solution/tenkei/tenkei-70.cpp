#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i = 0; i < N; i++)
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<ll> vx(N);
  vector<ll> vy(N);

  rep(i, N) {
    cin >> vx[i] >> vy[i];
  }

  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());

  ll x = vx[N/2];
  ll y = vy[N/2];


  ll res = 0;
  rep(i, N) {
    res += abs(vx[i] - x) + abs(vy[i] - y);
  }

  cout << res << endl;
}
