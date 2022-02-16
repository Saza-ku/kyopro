#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair
#define pb push_back

using ll = long long;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

ll point(string s) {
  ll ret = 0;
  for (int i = 1; i < 10; i++) {
    ll tmp = 1;
    rep (j, 5) {
      if (s[j] - '0' == i) tmp *= 10;
    }
    ret += i * tmp;
  }
  return ret;
}

ll gcd(ll m, ll n) {
  ll a = max(m, n);
  ll b = min(m, n);
  ll r = a % b;

  while(r != 0){
    a = b;
    b = r;
    r = a % b;
  }

  return b;
}

int main() {
  cout << fixed << setprecision(14);
  ll K;
  string s, t;
  cin >> K >> s >> t;
  vector<ll> cards(10, K);

  rep (i, 4) {
    cards[s[i] - '0']--;
    cards[t[i] - '0']--;
  }

  ll b = (9 * K - 8) * (9 * K - 9);
  ll a = 0;

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      s[4] = i + '0';
      t[4] = j + '0';
      if (point(s) <= point(t)) continue;

      if (i == j) {
        a += cards[i] * (cards[i] - 1);
      } else {
        a += cards[i] * cards[j];
      }
    }
  }

  if (a == 0) {
    cout << 0 << endl;
    return 0;
  }
  ll g = gcd(a, b);
  cout << double(a / g) / (b / g) << endl;
}
