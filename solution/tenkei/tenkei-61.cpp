#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int Q;
  cin >> Q;
  deque<int> deq;

  rep(i, Q) {
    int t, x;
    cin >> t >> x;
    if (t == 1) deq.push_front(x);
    else if (t == 2) deq.push_back(x);
    else cout << deq[x - 1] << endl;
  }
}