#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

struct UnionFind{
  //メンバ変数 
  vector<long long>par; //par[i]:=頂点iの親
  vector<long long>s; //s[i]:=頂点iが属する集合の個数(iが根のとき)
  
  //コンストラクタ
  UnionFind(long long N):par(N),s(N){
    for(long long i=0;i<N;i++){
      par[i]=i; //最初はすべてが根として初期化
      s[i]=1;
    }
  }
  //メンバ関数
  //root(i):=頂点iの根
  long long root(long long i){
    if(par[i]==i) return i;
    par[i]=root(par[i]); //経路圧縮
    return root(par[i]); //再帰
  }
  //size[i]:=iが属する集合の個数
  long long size(long long i){
    return s[root(i)];
  }
  //same(x,y) xとyが同じ根を持つか(同じ集合に含まれるか)
  bool same(long long x, long long y){
    return root(x)==root(y);
  }
  //unite(x,y) xの根をyの根に繋げる(集合を合併)
  void unite(long long x, long long y){
    if(!same(x,y)){
      long long rx=root(x);
      long long ry=root(y);
      par[rx]=par[ry];
      s[ry]=s[rx]+s[ry];
    }
  }
};

vector<int> isPassed(101010, false);
vector<vector<int>> graph(101010);

// dfs(今いるノード, 一つ前にいたノード)
bool dfs(const int current, const int before) {
    isPassed[current] = true;
    for(int i = 0; i < graph[current].size(); i++) {
        if(graph[current][i] == before) {
            // 前のノードに戻る場合
            continue;
        }
        if(isPassed[ graph[current][i] ]) {
            // 次に行くノードがかこに通ったことがある場合
            return true;
        }
        dfs(graph[current][i], current);
    }
    return false;
}

int main() {
  ll N, M;
  cin >> N >> M;
  set<pair<int, int>> s;
  vector<int> table(N);
  bool OK = true;
  rep (i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    auto p = mkp(min(a, b), max(a, b));
    if (s.count(p)) continue;
    s.insert(p);

    table[a]++;
    table[b]++;
    if (table[a] > 2 || table[b] > 2) {
      OK = false;
    }
    
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  if (!OK) {
    cout << "No" << endl;
    return 0;
  }

  rep (i, N) {
    if (isPassed[i]) continue;
    if (dfs(i, -1)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
