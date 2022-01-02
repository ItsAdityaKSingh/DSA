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

struct fraction{
	ll num;
	ll den;
	fraction(){
		num=1;
		den=1;
	}
	fraction(pair<ll,ll> a){
        ll g=__gcd(a.F,a.S);
        num=a.F/g;
        den=a.S/g;
        if(den<0){
            num*=-1;
            den*=-1;
        }
	}
    fraction inv(){
        fraction res;
        res.num=den;
        res.den=num;
        if(res.den<0){
            res.num*=-1;
            res.den*=-1;
        }
        return res;
    }
	fraction add(fraction a){
		fraction res;
        res.num=(num*a.den+a.num*den);
        res.den=den*a.den;
        ll g=__gcd(res.num,res.den);
        res.num/=g;
        res.den/=g;
        if(res.den<0){
            res.num*=-1;
            res.den*=-1;
        }
		return res;
	}
    fraction subtract(fraction a){
        fraction self;
        self.num=num,self.den=den;
        a.num*=-1;
        return self.add(a);
    }
    fraction multiply(fraction a){
        fraction res;
        res.num=num*a.num;
        res.den=den*a.den;
        ll g=__gcd(res.num,res.den);
        res.num/=g;
        res.den/=g;
        if(res.den<0){
            res.num*=-1;
            res.den*=-1;
        }
        return res;
    }
    fraction divide(fraction a){
        fraction self;
        self.num=num,self.den=den;
        fraction res=a.inv().multiply(self);
        return res;
    }
	void print(){
		cout<<num<<"/"<<den<<endl;
	}
};

void torment() {
    ll a,b;
    cin>>a>>b;
    fraction f1({a,b});
    ll c,d;
    cin>>c>>d;
    fraction f2({c,d});
    // f1.multiply(f2).print();
    // f1.inv().print();
    // auto f3=f1.inv();
    // f3.multiply(f2).print();
    f1.divide(f2).print();
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