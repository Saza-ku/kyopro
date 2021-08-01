#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int N, K;
  cin >> N >> K;
  int res = 0;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  int right = -1;
  map<int, int> table;
  for (int left = 0; left < N; left++) {
    while (table.size() <= K && right < N) {
      right++;
      if (table.count(a[right])) table[a[right]]++;
      else table[a[right]] = 1;
    }

    res = max(res, right - left);
    // cout << left << " " << right << " " << table.size() << endl;
    table[a[left]]--;
    if (table[a[left]] == 0) table.erase(a[left]);
  }

  cout << res << endl;
}
