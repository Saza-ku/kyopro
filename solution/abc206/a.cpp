#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  int p = 108 * N / 100;
  if (p < 206) cout << "Yay!" << endl;
  else if (p > 206) cout << ":(" << endl;
  else cout << "so-so" << endl;
}

