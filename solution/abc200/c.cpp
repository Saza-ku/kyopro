#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

int main() {
  int N; cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  vector<long long> m(200, 0);

  rep(i, N){
    int k = a[i] % 200;
    m[k]++;
  }

  ll res = 0;
  rep(i, 200){
    res += m[i] * (m[i] - 1) / 2;
  }
  cout << res << endl;
}
