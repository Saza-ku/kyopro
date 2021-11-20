#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
ll mod = 998244353;

long long repeat_squaring(long long x, long long n){
  x %= mod;
  if(n==0) return 1;
  else if(n%2==0){
    long long t=repeat_squaring(x,n/2);
    return t*t%mod;
  }
  else
    return x*repeat_squaring(x,n-1)%mod;
}

int main() {
  ll N, K, M;
  cin >> N >> K >> M;

  if (M % mod == 0) {
    cout << 0 << endl;
    return 0;
  }

  mod = mod - 1;
  ll x = repeat_squaring(K, N);
  mod = mod + 1;
  ll res = repeat_squaring(M, x);
  cout << res << endl;
}
