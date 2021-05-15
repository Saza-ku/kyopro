#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

int main() {
	int N; cin >> N;
	vector<pair<int, string>> a(N);
	rep(i, N){
		cin >> a[i].second >> a[i].first;
	}

	sort(a.rbegin(), a.rend());

	cout << a[1].second << endl;
}
