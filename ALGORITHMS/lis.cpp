#include<bits/stdc++.h>
using namespace std;

template<typename T>
int lis(vector<T> &v, T inf) {
	int n = v.size();
	vector<T> dp(n, inf);
	for(int i = 0; i < n; i++) {
		int _i = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
		dp[_i] = v[i];
	}
	for(int i = 0; i < n; i++) {
		if(dp[i] == inf)
			return i;
	}
	return n;
}

template<typename T>
int lnds(vector<T> &v, T inf) {
	int n = v.size();
	vector<T> dp(n, inf);
	for(int i = 0; i < n; i++) {
		int _i = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
		dp[_i] = v[i];
	}
	for(int i = 0; i < n; i++) {
		if(dp[i] == inf)
			return i;
	}
	return n;
}

int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << lis(v, (long long) 1e18) << endl;
	cout << lnds(v, (long long) 1e18) << endl;
}