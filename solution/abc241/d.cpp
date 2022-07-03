#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair
#define pb push_back

using ll = long long;

const int INF = 1e9;
const ll INFL = 2e18;
const int MOD = 1e9 + 7;

bool is_valid(int i) {
  return i != -1 || i != INFL;
}

template <typename T>
vector<T> compress(vector<T> &X) {
    // ソートした結果を vals に
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    // 各要素ごとに二分探索で位置を求める
    for (int i = 0; i < (int)X.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}

int main() {
  ll Q;
  cin >> Q;
  vector<vector<ll>> q;
  
  rep(i, Q) {
    ll n;
    cin >> n;
    if (n == 0) {
      int x;
      cin >> x;
      q[n][1] = x;
      q[n][2] = 0;
    } else {
      int x, k;
      cin >> x >> k;
      q[n][1] = x;
      q[n][2] = k;
    }
  }


}
