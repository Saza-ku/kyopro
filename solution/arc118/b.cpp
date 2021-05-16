#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

// a / b
ll ceildiv(ll a, ll b){
  return (a + b - 1) / b;
}

int main() {
  ll K, M, N; cin >> K >> N >> M;

  vector<ll> a(K);
  rep(i, K) cin >> a[i];

  ll ok = 1e9, ng = 0;

  while(abs(ok - ng) > 1){
    ll x = (ok + ng) / 2;

    vector<ll> b(K);
    ll sum_b = 0;
    ll sum_d = 0;
    rep(i, K-1){
      b[i] = max(0LL, ceildiv(M*a[i] - x, N));
      sum_b += b[i];
      sum_d += (M*a[i] + x) / N - b[i];
    }
    ll b_n = M - sum_b;
    ll l = max(0LL, ceildiv(M*a[K-1] - x, N));
    ll r = (M*a[K-1] + x) / N;
    if(l <= b_n && b_n <= r ||
      r < b_n && b_n - sum_d <= r){
        ok = x;
    }
    else{
      ng = x;
    }
  }

  ll x = ok;
  vector<ll> b(K);
  vector<ll> d(K);
  ll sum_b = 0;
  rep(i, K-1) {
    b[i] = max(0LL, ceildiv(M*a[i] - x, N));
    sum_b += b[i];
    d[i] = (M*a[i] + x) / N - b[i];
  }

  b[K-1] = M - sum_b;

  ll r = (M*a[K-1] + x) / N;

  for(ll i = 0; i < K-1 && r < b[K-1]; i++){
    b[K-1] -= d[i];
    b[i] += d[i];
  }

  rep(i, K) cout << b[i] << " ";
  cout << endl;

  //cout << ok << endl;
}
