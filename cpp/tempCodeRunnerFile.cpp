#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

using ll = long long;

#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>
#define mkp make_pair

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> H(N), W(M);
	for(int i = 0; i < N; i++) cin >> H[i];
	for(int i = 0; i < M; i++) cin >> W[i];
  int res = 1e9;
	sort(H.begin(), H.end());
	sort(W.begin(), W.end());

  // 累積話作る
  vector<int> sum_odd(N+1, 0), sum_even(N+1, 0);
	vector<int> p(N);
	for(int i = 0; i < N - 1; i++){
		p[i] = H[i+1] - H[i];
	}
	p[N-1] = 0;
  for(int i = 0; i < N; i++){
    if(i % 2 == 0){
			sum_even[i+1] = sum_even[i] + p[i];
			sum_odd[i+1] = sum_odd[i];
    }
		else{
			sum_even[i+1] = sum_even[i];
			sum_odd[i+1] = sum_odd[i] + p[i];
		}
  }

  for(int i = 0; i < N; i++){
		int tmp = 0;
    // 先生と組む
    auto iter = lower_bound(W.begin(), W.end(), H[i]);
    int diff = abs(*iter - H[i]);
		iter--;
    diff = min(abs(*iter - H[i]), diff); //done

    // 残りで組む
		if(i % 2 == 0){
		  tmp += sum_even[i-1];
		  tmp += sum_odd[N] - sum_odd[i];
		}
		else{
			tmp += H[i+1] - H[i-1];
			tmp += sum_even[i-1];
			tmp += sum_odd[N] - sum_odd[i+1];
		}

    // 合計計算
		tmp += diff;
		res = min(res, tmp);
		//cout << tmp << endl;
  }
	cout << res << endl;

	// debug
	/*
	cout << res << endl;
	for(int i = 0; i < N+1; i++){
		cout << sum_odd[i] << " " << sum_even[i] << endl;
	}
	*/
}