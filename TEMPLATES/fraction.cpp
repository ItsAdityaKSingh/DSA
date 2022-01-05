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
    ll gcd(ll a,ll b){
        return (!a&&!b?1:__gcd(abs(a),abs(b)));
    }
    fraction(){
        num=1;
        den=1;
    }
    fraction(pair<ll,ll> a){
        ll g=gcd(a.F,a.S);
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
    fraction operator + (fraction a){
        fraction res;
        res.num=(num*a.den+a.num*den);
        res.den=den*a.den;
        ll g=gcd(res.num,res.den);
        res.num/=g;
        res.den/=g;
        if(res.den<0){
            res.num*=-1;
            res.den*=-1;
        }
        return res;
    }
    fraction operator - (fraction a){
        fraction self;
        self.num=num,self.den=den;
        a.num*=-1;
        return self+a;
    }
    fraction operator * (fraction a){
        fraction res;
        res.num=num*a.num;
        res.den=den*a.den;
        ll g=gcd(res.num,res.den);
        res.num/=g;
        res.den/=g;
        if(res.den<0){
            res.num*=-1;
            res.den*=-1;
        }
        return res;
    }
    fraction operator / (fraction a){
        fraction self;
        self.num=num,self.den=den;
        fraction res=a.inv()*self;
        return res;
    }
    void print() const{
        cout<<num<<"/"<<den;
    }
};
bool operator <(const fraction& l, const fraction& r) {
     return l.num*r.den<l.den*r.num;
};
bool operator >(const fraction& l, const fraction& r) {
     return l.num*r.den>l.den*r.num;
};
bool operator ==(const fraction& l, const fraction& r) {
     return l.num*r.den==l.den*r.num;
};
bool testFrac(){
    vector<vll> tc={
        {1,1,1,1},
        {3 ,4 ,5, 6},
        {232, 1 ,1 ,232},
        {-1733 ,-98233, -12323, -226},
        {1 ,0, 0, 1},
        {-1 ,0 ,0 ,1},
        {1 ,0 ,-1, 0},
        {4, 3, 3, 7},
        {12 ,256, 9, 18},
        {123, -196, -122, -99},
    };
    for(auto test:tc){
        fraction f1({test[0],test[1]});
        fraction f2({test[2],test[3]});
        cout<<"[ ";
        f1.print();
        cout<<" ";
        f2.print();
        cout<<" ]: ";
        (f1+f2).print();
        cout<<" ";
        (f1-f2).print();
        cout<<" ";
        (f1*f2).print();
        cout<<" ";
        (f1/f2).print();
        cout<<endl;
    }
}

int32_t main() {
    testFrac();
}