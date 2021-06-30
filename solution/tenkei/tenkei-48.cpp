#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

#define mkp make_pair

int main() {
  int N, K;
  cin >> N >> K;
  vector<P> ab(N);
  for (int i = 0; i < N; i++) {
    cin >> ab[i].first >> ab[i].second;
  }

  priority_queue<P> queue;
  vector<bool> untouched(N, true);
  for (int i = 0; i < N; i++) {
    queue.push(mkp(ab[i].second, i));
  }

  ll res = 0;
  for (int k = 0; k < K; k++) {
    int score, i;
    tie(score, i) = queue.top();
    queue.pop();

    res += score;
    if (untouched[i]) {
      queue.push(mkp(ab[i].first - ab[i].second, i));
      untouched[i] = false;
    }
  }
  cout << res << endl;
}
