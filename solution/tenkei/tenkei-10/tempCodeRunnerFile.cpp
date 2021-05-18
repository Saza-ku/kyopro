#include<bits/stdc++.h>

#define rep(i, N) for(int i = 0; i < N; i++)

using namespace std;
const long long INF = 1e18;

int main() {
  int N; cin >> N;
  vector<int> c_1(N);
  vector<int> c_2(N);

  rep(i, N){
      int c, p;
      cin >> c >> p;
      if(c == 1){
          c_1[i] = p;
          c_2[i] = 0;
      }
      else{
          c_1[i] = 0;
          c_2[i] = p;
      }
  }

  vector<int> sum_1(N+1, 0);
  vector<int> sum_2(N+1, 0);
  rep(i, N){
      sum_1[i+1] = sum_1[i] + c_1[i];
      sum_2[i+1] = sum_2[i] + c_2[i];
  }

  int Q; cin >> Q;

  rep(i, Q){
      int l, r; cin >> l >> r;
      l--; r--;
      cout << sum_1[r+1] - sum_1[l] << " " << sum_2[r+1] - sum_1[i] << endl;
  }

}

