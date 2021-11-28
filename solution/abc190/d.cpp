#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

ll N;

bool is_ans(ll n) {
  return (2*N / n - n) % 2 == 1 || (2*N / n - n) % 2 == -1;
}

int main() {
  cin >> N;

  ll res = 0;
  for (ll i = 1; i * i <= 2*N; i++) {
    if (2*N % i == 0) {
      ll n = i;
      if (is_ans(n)) {
        res++;
      }
      if (i * i != N) n = 2*N / i;
      if (is_ans(n)) {
        res++;
      }
    }
  }

  cout << res << endl;
}
