#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

struct union_find{
  vector<ll> par;
  vector<ll> s;

  union_find(long long N) : par(N), s(N) {
    rep (i, N) {
      par[i] = i;
      s[i] = 1;
    }
  }

  ll root(ll i){
    if (par[i] == i) return i;
    par[i] = root(par[i]);
    return root(par[i]);
  }

  ll size(ll i){
    return s[root(i)];
  }
 
  bool same(ll x, ll y){
    return root(x) == root(y);
  }
  
  void unite(ll x, ll y){
    if(!same(x,y)){
      ll rx = root(x);
      ll ry = root(y);
      par[rx] = par[ry];
      s[ry] = s[rx] + s[ry];
    }
  }
};

int main() {
  int N;
  cin >> N;
  union_find u(1000000);
  vector<int> a(N);
  rep (i, N) cin >> a[i];

  rep (i, N / 2) {
    // cerr << i << " " << N - 1 - i << endl;
    u.unite(a[i], a[N - 1 - i]);
  }

  set<int> done;

  int res = 0;
  rep (i, 1000000) {
    int r = u.root(i);
    if (done.count(r)) continue;

    res += u.size(r) - 1;
    // cerr << r << " " << u.size(r) << endl;
    done.insert(r);
  }

  cout << res << endl;
}
