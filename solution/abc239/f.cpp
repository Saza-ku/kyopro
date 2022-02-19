#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair
#define pb push_back

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
  int N, M;
  ll sum = 0;
  cin >> N >> M;
  vector<int> v(N);
  priority_queue<pair<int, int>> q;
  rep (i, N) {
    cin >> v[i];
    sum += v[i];
  }
  union_find uf = union_find(N);
  if (sum != (N-1) * 2) {
    cout << -1 << endl;
    return 0;
  }
  rep (i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    v[a]--;
    v[b]--;
    uf.unite(a, b);
  }
  rep (i, N) {
    q.push(mkp(v[i], i));
  }
  vector<pair<int, int>> res;

  while(q.size() > 0) {
    int d, u;
    tie(d, u) = q.top(); q.pop();
    if (d < 0) {
      cout << -1 << endl;
      return 0;
    }
    vector<pair<int, int>> tmp;
    rep (i, d) {
      int x, v;
      if (q.empty()) {
        cout << -1 << endl;
        return 0;
      }
      tie(x, v) = q.top(); q.pop();
      if (uf.same(u, v)) {
        i--;
        tmp.pb(mkp(x, v));
        continue;
      }
      tmp.pb(mkp(x-1, v));
      res.pb(mkp(u, v));
      uf.unite(u, v);
    }
    for (auto p : tmp) {
      q.push(p);
    }
  }

  for (auto p : res) {
    cout << p.first + 1 << " " << p.second + 1 << endl;
  }
}
