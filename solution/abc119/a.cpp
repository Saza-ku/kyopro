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
  string s;
  cin >> s;
  if (s[5] == '1' || (s[6] - '0') > 4) {
    cout << "TBD" << endl;
  } else {
    cout << "Heisei" << endl;
  }
}
