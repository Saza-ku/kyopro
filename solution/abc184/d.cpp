#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;

double dp[105][105][105];

double f(int a, int b, int c) {
  if (dp[a][b][c]) return dp[a][b][c];
  if (a == 100 || b == 100 || c == 100) return 0;
  double res = 0;
  res += (f(a + 1, b, c) + 1) * a / (a + b + c);
  res += (f(a, b + 1, c) + 1) * b / (a + b + c);
  res += (f(a, b, c + 1) + 1) * c / (a + b + c);
  dp[a][b][c] = res;
  return res;
}

int main() {
  cout<<fixed<<setprecision(14);
  int a, b, c;
  cin >> a >> b >> c;
  
  cout << f(a, b, c) << endl;
}
