#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int res = 0;
  rep(i, N) {
    int cnt = 0;
    int u = i;
    for (auto v : graph[i]) {
      if (v < u) cnt++;
    }
    if (cnt == 1) res++;
  }

  cout << res << endl;
}