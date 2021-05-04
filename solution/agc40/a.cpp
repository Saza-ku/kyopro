#include<bits/stdc++.h>

using namespace std;
const long long INF = 1e18;

int main() {
  string s; cin >> s;
  int N = s.size() + 1;

  int tmp = 0;
  int m = 0;
  int res = 0;
  int mount = 0;

  for(int i = 0; i < N-1; i++){
      if(s[i] == '<'){
          tmp++;
          res += tmp;
          mount = i;
      }
      else{
          tmp--;
          res += tmp;
          m = min(m, tmp);
      }
  }

  res -= m * N;

  cout << res << endl;
}