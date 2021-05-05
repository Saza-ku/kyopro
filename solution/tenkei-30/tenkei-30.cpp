#include<bits/stdc++.h>

#define rep(i, N) for(int i = 0; i < N; i++)

using namespace std;
const long long INF = 1e18;

int main() {
  int N, K; cin >> N >> K;

  vector<int> f(N+1, 0);

  for(int i = 2; i <= N + 1; i++){
      if(f[i] == 0){
          int p = i;
          for(int j = p; j <= N; j += p){
              f[j]++;
          }
      }
  }


int res = 0;
  for(int i = 2; i <= N; i++){
      if(f[i] == 0) f[i]++;
      if(f[i] >= K) res++;
      //cout << i << " " << f[i] << endl;
  }

  cout << res << endl;
}