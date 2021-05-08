#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

int main() {
  long long N; int K;
  cin >> N >> K;

  rep(i, K){
    if(N % 200 == 0) N /= 200;
    else{
      N *= 1000;
      N += 200;
    }
  }

  cout << N << endl;
}
