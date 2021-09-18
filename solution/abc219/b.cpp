#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const long long INF = 1e18;

int main() {
  string s[3];
  cin >> s[0] >> s[1] >> s[2];
  string t;
  cin >> t;
  rep (i, (int)t.size()) {
    int x = t[i] - '1';
    cout << s[x];
  }
  cout << endl;
}
