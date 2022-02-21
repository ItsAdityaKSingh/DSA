// these train of thoughts linger 
// as darkness falls in time

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

template<typename T>
int __lb(vector<T> &v, T val, T hi, T lo) {
	int n = v.size();
}

template<typename T>
ll lis(vector<T> v, T inf) {
	ll n = v.size();
	vector<T> dp(n + 1, inf);
	// dp[0] = inf * -1;
	for(ll i = 0; i < n; i++) {
		// 1 2 7 12 inf inf inf
		ll _i = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
		// if(dp[_i - 1] < v[i] && v[i] < dp[_i]) // pass to function 
		if(_i < n + 1)
			dp[_i] = v[i];
		
		// v[i] = 3
	}
	dbg(dp);
	ll ans=0;
	for(ll i = 0; i < n + 1; i++) {
	    if(dp[i] < inf) { // pass to func
	        ans = i + 1;
	    }
	}
	return ans;
}

signed main() {
	ll n;
	cin >> n;
	vector<ll> v(n);
	for(ll i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << lis(v, LLONG_MAX) << endl;
}

// anger, happiness and sadness
// won't mean a thing when...