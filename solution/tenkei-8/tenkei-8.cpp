// #Sazaの1日1AC
#include<bits/stdc++.h>
using namespace std;
//const long long mod=1e9+7;
const long long INF=9e18;
const double PI=3.14159265358979323846;
const int mod = 1e9 + 7;

//マクロ
//型エイリアス
using ll = long long;
using P=pair<long long, long long>;
using vl=vector<long long>;
using vvl=vector<vector<long long>>;
using vP=vector<pair<long long, long long>>;
//ショートカット
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,k,n) for(long long i = k; i < n; i++) //半開区間
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mkp make_pair
//入力
#define vin(v,N) for(long long i=0;i<N;i++) cin>>v.at(i)
#define lin(n) long long n;cin>>n
#define chin(x) char x;cin>>x;
#define sin(s) string s;cin>>s;
#define vlin(v,N) vector<long long>v(N);for(long long i=0;i<N;i++)cin>>v.at(i)

/*
//関数
//最大公約数
long long gcd(long long m, long long n){
  long long a=max(m,n);
  long long b=min(m,n);
  long long r=a%b;
  while(r!=0){
    a=b; b=r; r=a%b;
  }
  return b;
}
// 最小公倍数
long long lcd(long long m, long long n){
  return m*n/gcd(m,n);
}
//xのn乗
long long power(long long x, long long N){
  long long ret=1;
  for(long long i=0;i<N;i++)   
    ret*=x;
  return ret;
}
//繰り返し二乗法
long long repeat_squaring(long long x, long long n){
  if(n==0) return 1;
  else if(n%2==0){
    long long t=repeat_squaring(x,n/2);
    return t*t%mod;
  }
  else
    return x*repeat_squaring(x,n-1)%mod;
}
//素因数分解(mapで返す)
map<int,int> factor(long long p){
  ll p1=p;
  map<int, int>ret;
  for(int i=2;i*i<=p1;i++){
     while(p%i==0){
      ret[i]++;
      p/=i;
    }
  }
  if(p!=1)
  ret[p]++;
  return ret;
}
//素数判定
bool is_prime(long long N){
  for(long long i=2;i*i<=N;i++){
    if(N%i==0)
      return false;
  }
  return true;
}
//最大値更新
void chmax(long long &a,long long b){
  a=max(a,b);
}
//最小値更新
void chmin(long long &a,long long b){
  a=min(a,b);
}

//構造体

//Union-Find木
struct UnionFind{
  //メンバ変数 
  vector<long long>par; //par[i]:=頂点iの親
  vector<long long>s; //s[i]:=頂点iが属する集合の個数(iが根のとき)
  
  //コンストラクタ
  UnionFind(long long N):par(N),s(N){
    for(long long i=0;i<N;i++){
      par[i]=i; //最初はすべてが根として初期化
      s[i]=1;
    }
  }
  //メンバ関数
  //root(i):=頂点iの根
  long long root(long long i){
    if(par[i]==i) return i;
    par[i]=root(par[i]); //経路圧縮
    return root(par[i]); //再帰
  }
  //size[i]:=iが属する集合の個数
  long long size(long long i){
    return s[root(i)];
  }
  //same(x,y) xとyが同じ根を持つか(同じ集合に含まれるか)
  bool same(long long x, long long y){
    return root(x)==root(y);
  }
  //unite(x,y) xの根をyの根に繋げる(集合を合併)
  void unite(long long x, long long y){
    if(!same(x,y)){
      long long rx=root(x);
      long long ry=root(y);
      par[rx]=par[ry];
      s[ry]=s[rx]+s[ry];
    }
  }
};
*/
/////////////////⊂('ω'⊂ )))Σ≡GO!/////////////////


int main() {
	int N; string s;
	cin >> N >> s;

	vector<vector<ll>> dp(N + 10, vector<ll>(7, 0));

	rep(i, N){
		if(i > 0){
			rep(j, 7) {
				dp[i][j] = dp[i-1][j];
		}
		}
		if(s[i] == 'a'){
			dp[i][0]++;
		}

		if(i > 0){
			switch(s[i]){
				case 't': dp[i][1] += dp[i-1][0]; break;
				case 'c': dp[i][2] += dp[i-1][1]; break;
				case 'o': dp[i][3] += dp[i-1][2]; break;
				case 'd': dp[i][4] += dp[i-1][3]; break;
				case 'e': dp[i][5] += dp[i-1][4]; break;
				case 'r': dp[i][6] += dp[i-1][5]; break;
				default: break;
			}
		}
		rep(j, 7){
			dp[i][j] = dp[i][j] % mod;
		}
	}
	cout << dp[N-1][6] << endl;
}