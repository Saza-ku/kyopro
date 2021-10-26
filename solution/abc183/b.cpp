#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

int main() {
  cout << fixed << setprecision(14);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  d *= -1;
  cout << double(a*d - b*c) / (d - b) << endl;
}
