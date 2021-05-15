#include<bits/stdc++.h>

using namespace std;

#define rep(i, N) for(int i = 0; i < N; i++)

using ll = long long;
const long long INF = 1e18;

set<int> inc;
set<int> exc;

int dfs(vector<int> v, int depth) {
	if(depth == 4){
		for(int n : inc){
			bool ok = false;
			rep(i, 4){
				if(v[i] == n) ok = true;
			}
			if(!ok) return 0;
		}
		rep(i, 4){
			if(exc.count(v[i])) return 0;
		}
		//cout << v[0] << v[1] << v[2] << v[3] << endl;
		return 1;
	}

	int ret = 0;
	rep(i, 10){
		v[depth] = i;
		ret += dfs(v, depth+1);
	}
	return ret;
}

int main() {
	string s; cin >> s;

	rep(i, 10){
		if(s[i] == 'o') inc.insert(i);
		if(s[i] == 'x') exc.insert(i);
	}
	vector<int> v(4);

	cout << dfs(v, 0) << endl;
}
