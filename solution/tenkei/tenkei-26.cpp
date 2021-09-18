#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const long long INF = 1e18;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> nodes(0);
  queue<pair<int, int>> q;
  vector<bool> reached(N, false);
  reached[0] = true;

  q.push(mkp(0, 0));
  while(!q.empty()) {
    int u, cnt;
    tie(u, cnt) = q.front();
    q.pop();
    if (cnt % 2 == 0) {
      nodes.push_back(u+1);
    }

    for (auto x : G[u]) {
      if (reached[x]) continue;
      q.push(mkp(x, cnt + 1));
      reached[x] = true;
    }
  }

  if (nodes.size() >= N / 2) {
    rep(i, N / 2) {
      cout << nodes[i] << " ";
    }
    cout << endl;
    return 0;
  }

  vector<int> hoge(0);
  nodes = hoge;

  rep(i, N) reached[i] = false;
  q.push(mkp(0, 1));
  reached[0] = true;
  while(!q.empty()) {
    int u, cnt;
    tie(u, cnt) = q.front();
    q.pop();
    if (cnt % 2 == 0) {
      nodes.push_back(u+1);
    }

    for (auto x : G[u]) {
      if (reached[x]) continue;
      q.push(mkp(x, cnt + 1));
      reached[x] = true;
    }
  }

  if (nodes.size() >= N / 2) {
    rep(i, N / 2) {
      cout << nodes[i] << " ";
    }
    cout << endl;
    return 0;
  }
}
