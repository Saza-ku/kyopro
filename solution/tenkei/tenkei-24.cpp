#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int N, K;
  cin >> N >> K;

  int diff = 0;
  vector<int> a(N), b(N);

  rep(i, N) cin >> a[i];
  rep(i, N) cin >> b[i];

  rep(i, N) {
    diff += abs(a[i] - b[i]);
  }

  if (diff % 2 == K % 2 && diff <= K) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
