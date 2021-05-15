#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

int main() {
	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());

	if(a[2] - a[1] == a[1] - a[0]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
