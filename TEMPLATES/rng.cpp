// these train of thoughts linger 
// as darkness falls in time

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define F first
#define S second
#define vll vector<ll>
#define fin(i,n1,n2) for(int i=n1;i<n2;i++)
#define nif(i,n1,n2) for(int i=n1;i>n2;i--)
#define all(x) x.begin(),x.end()
#define m69 998244353
#define m420 1000000007
void spit(auto x){for(auto e:x)cout<<e<<" ";cout<<endl;}
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)) && 1)

struct prng{
private:
	unsigned long long state=1;
	void next_rand() {
		state ^= state << 13;
		state ^= state >> 7;
		state ^= state << 17;
	}
public:
	prng(unsigned long long _state) {
		state=_state;
	}
	double flt() {
		next_rand();
		unsigned long long cur = state;
		return cur*1.0/ULLONG_MAX;
	}
};

void torment() {
    ll tc;
    cin>>tc;
    prng rng(rand()*rand()*rand()*rand());
    vll dig(12,0);
    while(tc--) {
    	ll cur=10*rng.flt();
    	dig[cur]++;
    }
    spit(dig);
}

int32_t main() {
	srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int32_t wrong_answer_on_pretest_2=1;
    // cin>>wrong_answer_on_pretest_2;
    while(wrong_answer_on_pretest_2--){
        torment();
    }
}

// anger, happiness and sadness
// won't mean a thing when...
