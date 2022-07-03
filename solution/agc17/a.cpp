#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair
#define pb push_back

using ll = long long;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int N, p;
  cin >> N >> p;
  int odd_count = 0, even_count = 0;
  rep (i, N) {
    int a;
    cin >> a;
    if (a % 2 == 0) {
      even_count++;
    } else {
      odd_count++;
    }
  }
  ll res1 = pow(2, even_count);

  int i;
  ll res2 = 0;
  ll tmp;
  if (p == 0) {
    i = 2;
    tmp = 1;
    res2 = 1;
  } else {
    i = 3;
    tmp = odd_count;
    res2 = odd_count;
  }
  for (; i <= odd_count; i += 2) {
    tmp *= (odd_count - (i - 2)) * (odd_count - (i - 1));
    tmp /= i * (i - 1);
    res2 += tmp;
  }

  if (p == 1 && odd_count == 0) {
    cout << 0 << endl;
    return 0;
  }

  cout << res1 * res2 << endl;
}
