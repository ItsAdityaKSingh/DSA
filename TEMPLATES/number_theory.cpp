#include<bits/stdc++.h>
#define ll long long
using namespace std;

namespace number_theory {
// NUMBER THEORY
bool isPrime(ll n) { 
    if (n <= 1) return false; 
    if (n <= 3) return true;       
    if (n % 2 == 0 || n % 3 == 0) return false;       
    for (ll i = 5; i * i <= n; i += 6) 
        if (n % i == 0 || n % (i+2) == 0) 
            return false;       
    return true; 
} 

set<ll> allFacts(ll n){
    set<ll> facs;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            facs.insert(i);
            facs.insert(n/i);
        }
    }
    return facs;
}

vector<ll> primes;
void sieve(ll n) {
    vector<bool> p(n+1,true);
    for(ll i=4;i<=n;i+=2) {
        p[i]=false;
    }
    for(ll i=3;i*i<=n;i+=2) {
        if(p[i]) {
            for(ll j=i*i;j<=n;j+=i) {
                p[j]=false;
            }
        }
    }
    for(ll i=2;i<=n;i++) {
        if(p[i]) {
            primes.push_back(i);
        }
    }
}
// prime factors
vector<pair<ll,ll>> primeFacts(ll n) {
    // call sieve first
    if(primes.size()==0){
        cout<<"call sieve"<<endl<<flush;
        exit(0);
    }
    vector<pair<ll,ll>> v;
    for(ll prime:primes) {
        if(prime*prime>n) break;
        ll exponent=0;
        while(n%prime==0) {
            n/=prime;
            exponent++;
        }
        if(exponent>0)
            v.push_back({prime,exponent});
    }
    if(n>1) {
        v.push_back({n,1});
    }
    return v;
}
// efficient power func
ll power(ll x, ll p) {
    if (p == 0) return 1;
    if (p == 1) return x; 
    ll tmp = power(x, p/2);
    if (p%2 == 0) return tmp * tmp;
    else return x * tmp * tmp;
}
ll modp(ll x, ll unsigned y, ll p) {
    ll res = 1; 
    x = x % p;
    if (x == 0) return 0; 
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

ll modInverse(ll a, ll p) {
    return modp(a, p-2, p);
}
// nCr mod P
ll nCRmodP(ll n, ll k, ll p) {
    ll numerator = 1;
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }
    ll denominator = 1;
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }
    return ( numerator* modInverse(denominator,p) ) % p;
}

ll factmod(ll n, ll d, ll p, ll exc) {
    // returns n!*(exc)/d!  mod p
    ll ans = 1;
    for(ll i=n;i>d;i--) {
        if(i==exc)continue;
        ans*=i;
        ans=ans%p;
    }
    return ans%p;
}
ll C(ll n, ll r) {
    // n C r efficient
    if(r>n) return 0;
    if(r > n - r) r = n - r;
    ll ans = 1;
    ll i;
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}

}
using namespace number_theory;


int main() {
    ll a;
    cin>>a;
    cout<<isPrime(a);
    return 0;
}

