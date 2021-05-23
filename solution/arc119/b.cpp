#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

int main() {
  int N;
  string s, t;
  cin >> N >> s >> t;
  int cnt_s = 0, cnt_t = 0;
  rep(i, N){
    if(s[i] == '0') {
      cnt_s++;
    }
    if(t[i] == '0') {
      cnt_t++;
    }
  }

  if(cnt_s != cnt_t) {
    cout << -1 << endl;
    return 0;
  }

  int K = cnt_s;

  vector<int> zero_s, zero_t;
  rep(i, N){
    if(s[i] == '0') {
      zero_s.push_back(i);
    }
    if(t[i] == '0') {
      zero_t.push_back(i);
    }
  }

  int ret = 0;
  rep(i, K) {
    if(zero_s[i] != zero_t[i]) {
      ret++;
    }
  }

  cout << ret << endl;
}