#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <functional>
using namespace std;

int mod = 100003;

int is_ok(vector<int> c, vector<int> v) {
  int first = 0, second = 0;

  int N = v.size();

  for (int i = 0; i < N; i++) {
    int t = c[v[i]];
    if (t < second) return 0;
    if (first < t) {
      second = first;
      first = t;
    }
    else if (second < t) {
      second = t;
    }
  }
  return 1;
}

int main() {
  int N;
  cin >> N;
  vector<int> c(N);
  for (int i = 0; i < N; i++) cin >> c[i];

  vector<int> v(N);
  for(int i = 0; i < N; i++) v[i] = i;

  int res = 0;

  do {
    res += is_ok(c, v);
    res %= mod;
  } while (next_permutation(v.begin(), v.end()));

  cout << res << endl;
}
