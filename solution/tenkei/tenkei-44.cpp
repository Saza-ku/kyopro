#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  int shift = 0;

  rep(q, Q) {
    int t, x, y;
    cin >> t >> x >> y;
    x--; y--;
    x = (x + shift) % N;
    y = (y + shift) % N;
    if (t == 1) {
      int tmp = a[x];
      a[x] = a[y];
      a[y] = tmp;
    }
    else if (t == 2) {
      shift++;
      shift %= N;
    }
    else {
      cout << a[x] << endl;
    }
  }
  rep(i, N) {
    int j = (i + shift) % N;
    cout << a[j] << endl;
  }
}