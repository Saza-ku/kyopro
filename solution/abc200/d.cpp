#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

int main() {
  int N; cin >> N;
  vector<int> a(N);
  rep(i, N){
    cin >> a[i];
    a[i] %= 200;
  }

  if(N >= 21){
    map<int, pair<int, int>> m;
    rep(i, N){
      for(int j = i + 1; j < N; j++) {
        int c = (a[i] + a[j]) % 200;
        rep(k, N){
          if(a[k] == c){
            cout << "Yes" << endl;
            cout << 1 << " " << k + 1 << endl;
            cout << 2 << " " << i + 1 << " " << j + 1 << endl;
            return 0;
          }
        }

        if(m.count(c)){
          cout << "Yes" << endl;
          cout << 2 << " " << i+1 << " " << j+1 << endl;
          cout << 2 << " " << m[c].first+1 << " " << m[c].second+1 << endl;
          return 0;
        }
        
        m[c] = make_pair(i, j);
      }
    }
  }

  else{
    map<int, vector<int>> m;
    rep(bit, (1 << N)){
      if(bit == 0) continue;
      vector<int> s;
      int c = 0;
      rep(i, N){
        if(bit & (1 << i)){
          s.push_back(i);
          c += a[i];
        }
      }

      c %= 200;

      if(m.count(c)){
        cout << "Yes" << endl;
        vector<int> t = m[c];

        cout << t.size() << " ";
        for(int j = 0; j < int(t.size()); j++) cout << t[j] + 1 << " ";
        cout << endl;

        cout << s.size() << " ";
        for(int j = 0; j < int(s.size()); j++) cout << s[j] + 1 << " ";
        cout << endl;

        return 0;
      }

      m[c] = s;
    }
  }

  cout << "No" << endl;
}
