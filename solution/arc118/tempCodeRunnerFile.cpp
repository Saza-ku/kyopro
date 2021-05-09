#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

int main() {
  ll K, M, N;
  cin >> K >> N >> M;
  vector<ll> a(K);
  rep(i, K) cin >> a[i];

  double ng = 0, ok = 10000000.0;

  rep(i, 100){
    ll tmp = M;
    double mid = (ok + ng) / 2;
    vector<ll> d(K-1);
    vector<ll> b(K-1);
    ll sum_b = 0;
    ll sum_d = 0;
    rep(i, K-1){
      ll l = max(0LL, ll(ceil(-M*mid + double(M*a[i])/N)));
      ll r = max(0LL, ll(floor(M*mid + double(M*a[i])/N)));

      b[i] = l;
      d[i] = r - l;
      sum_b += b[i];
      sum_d += d[i];
    }
    ll b_k = M - sum_b;
    ll l = max(0LL, ll(ceil(-M*mid + double(M*a[K-1])/N)));
    ll r = max(0LL, ll(floor(M*mid + double(M*a[K-1])/N)));

    //cout << b_k << " " << l << " " << r << " " << sum_d << endl;

    if(l <= b_k && b_k <= r ||
        r < b_k && b_k - sum_d <= r){
        ok = mid;
        //cout << "Ok" << endl;
    }
    else {
      ng = mid;
      //cout << "NG" << endl;
    }
  }

  ll tmp = M;
  vector<ll> d(K-1);
  vector<ll> b(K);
  ll sum_b = 0;
  ll sum_d = 0;
  rep(i, K-1){
    ll l = max(0LL, ll(ceil(-M*ok + double(M*a[i])/N)));
    ll r = max(0LL, ll(floor(M*ok + double(M*a[i])/N)));

    b[i] = l;
    d[i] = r - l;
    sum_b += b[i];
    sum_d += d[i];
  }
  ll b_k = M - sum_b;
  //cout << M << " " << sum_b << " " << b_k << endl;
  ll l = max(0LL, ll(ceil(-M*ok + double(M*a[K-1])/N)));
  ll r = max(0LL, ll(floor(M*ok + double(M*a[K-1])/N)));
  b[K-1] = b_k;

  if(r < b_k && b_k - sum_d <= r){
    rep(i, K-1){
      ll dif = min(d[i], b[K-1] - r);
      b[K-1] -= dif;
      b[i] += dif;
      //cout << " " << dif << " " << b[K-1] << " " << b[i] << endl;
      if(b[K-1] <= r) break;
    }
  }
  else{
    b[K-1] = b_k;
  }

  rep(i, K){
    cout << b[i] << " ";
  }
  cout << endl;
  //cout << sum_b << endl;
  //cout << ok << endl;
}