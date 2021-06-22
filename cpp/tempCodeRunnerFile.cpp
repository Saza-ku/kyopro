#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <functional>
using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;

  long long tmp = 1;

  vector<long long> primes(M + 10);

  vector<long long> table(M + 10);

  long long t = M;

  for (int i = 2; i*i <= M; i++) {
    t /= i;
    if (table[i] != 0) continue;
    long long x = i;
    while (true) {
      long long cnt = M / x;
      if (cnt == 0) break;
      primes[i] += cnt;
      x *= x;
    }
    for (int j = i; j*j <= M; j *= i) {
      table[j]++;
    }
  }

  for (int p = 2; p*p <= M; p++) {
    if (primes[p] == 0) continue;
  }

  cout << "Factorial" << endl;
}