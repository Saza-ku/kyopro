#include<bits/stdc++.h>

using namespace std;
const long long INF = 1e18;

int main() {
  string a, b;
  cin >> a >> b;

  for(int i = 0; i < max(a.size(), b.size()); i++){
	  if(a[i] != b[i])
	  cout << a[i] << ":" << b[i] << " " << i << endl;
  }
  cout << a.size() << endl;
}