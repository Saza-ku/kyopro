#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair
#define pb push_back

using ll = long long;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

bool is_prime(long long N){
  for(long long i=2;i*i<=N;i++){
    if(N%i==0)
      return false;
  }
  return true;
}

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  b++; d++;

  for (int i = a; i < b; i++) {
    bool can_win = true;
    for (int j = c; j < d; j++) {
      if (is_prime(i + j)) {
        can_win = false;
      }
    }
    if (can_win) {
      cout << "Takahashi" << endl;
      return 0;
    }
  }
  cout << "Aoki" << endl;
}
