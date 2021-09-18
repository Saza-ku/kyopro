#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)
#define mkp make_pair

using ll = long long;
const long long INF = 1e18;

int main() {
  int X;
  cin >> X;
  if (X < 40) {
    cout << 40 - X << endl;
    return 0;
  }
  if (X < 70) {
    cout << 70 - X << endl;
    return 0;
  }
  if (X < 90) {
    cout << 90 - X << endl;
    return 0;
  }
  cout << "expert" << endl;
}
