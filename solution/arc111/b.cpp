#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  vector<int> table(400000 + 10, 0);
  vector<pair<int, int>> cards(N);
  rep (i, N) {
    int a, b;
    cin >> a >> b;
    table[a]++;
    table[b]++;
    cards[i] = mkp(a, b);
  }

  int res = 0;
  set<int> done;
  rep (i, N) {
    int a, b;
    int c;
    tie(a, b) = cards[i];
    if (table[a] < table[b] && !done.count(a)) {
      c = a;
    }
    else {
      c = b;
    }
    if (!done.count(c)) {
      res++;
      done.insert(c);
    }
  }

  cout << res << endl;
}
