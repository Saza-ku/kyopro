#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

int main() {
  ll N; cin >> N;
  ll K; cin >> K;

  ll first = K / (N*N) + 1;

  ll r = K % N*N;

  second = 