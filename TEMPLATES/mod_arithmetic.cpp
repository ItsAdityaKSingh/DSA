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

ll modmul(ll a,ll b,ll mod){
    return a*b%mod;
}
ll modsub(ll a,ll b,ll mod){
    return ((a-b)%mod+mod)%mod;
}
ll modadd(ll a,ll b,ll mod){
    return ((a+b)%mod+mod)%mod;
}
ll modp(ll base,ll exp,ll mod){
    ll res=1;
    while(exp){
        if(exp&1)
            res=(res*base)%mod;
        exp/=2;
        base=(base*base)%mod;
    }
    return res;
}
ll modinv(ll a,ll mod){
    return modp(a,mod-2,mod);
}
ll mdiv(ll a,ll b,ll mod) {
    return a*(modinv(b,mod))%mod;
}
vll ncr;
void compute_ncr(ll n,ll mod) {
    ncr=vll(n+1,1);
    fin(i,0,n){
        ncr[i+1]=ncr[i]*(n-i)%mod;
        ncr[i+1]=ncr[i+1]*modinv(i+1,mod)%mod;
    }
}
vll facts;
void compute_facts(ll n,ll mod) {
    facts=vll(n+1,1);
    fin(i,0,n)
        facts[i+1]=modmul(facts[i],i+1,mod);
}

void torment() {
    // ll a,b,mod;
    // cin>>a>>b>>mod;
    // cout<<((ll)pow(a,b) % mod)<<endl;
    // cout<<modp(a,b,mod)<<endl;
    // cout<<mdiv(a,b,mod)<<endl;
    // cout<<modmul(a,b,mod)<<endl;
    ll n;
    cin>>n;
    compute_facts(n, 13);
    spit(facts);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int32_t wrong_answer_on_pretest_2=1;
    // cin>>wrong_answer_on_pretest_2;
    while(wrong_answer_on_pretest_2--){
        torment();
    }
}