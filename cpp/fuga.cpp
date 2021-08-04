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

  vector<int> a(N+1);

  a[0] = 1;
  a[1] = 0;
  a[2] = 1;

  for (int n = 3; n < N+1; n++) {
    int s = 0;
    for (int i = 0; i < n;i++) {
      s += a[i] * (n - 1 - i);
      s %= mod;
    }

    a[n] = s;
    a[n] %= mod;
  }
  
  int s = 0;
  for (int i = 0; i < N+1; i++) {
    s += a[i];
    a[i] %= mod;
    //cout << s << " " << a[i] << endl;
  }

  cout << s << endl;
}
