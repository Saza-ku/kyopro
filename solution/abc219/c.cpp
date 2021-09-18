#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const long long INF = 1e18;

int main() {
  map<char, int> alph;
  for (int i = 0; i < 26; i++) {
    char a;
    cin >> a;
    alph[a] = i;
  }

  int N;
  cin >> N;
  vector<string> s(N);
  rep(i, N) cin >> s[i];
  vector<pair<ll, string>> v(N);
  for (int i = 0; i < N; i++) {
    string t = s[i];
    ll value = 0;
    rep(j, (int)t.size()) {
      ll a = alph[t[j]];
      value += a * pow(26, 9 - j);
    }
    v[i] = mkp(value, t);
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < N; i++) {
    cout << v[i].second << endl;
  }
}
