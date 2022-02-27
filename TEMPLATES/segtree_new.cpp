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

template <typename T>
struct segtree{
    int n;
    T BASE_CASE=0;
    vector<T> tree;
    T (*f)(T a,T b);
    segtree(vector<T> &ar){
        n=ar.size();
        tree=vector<T>(4*n+1,0);
        f = [](T a,T b)-> T{
            return a+b;
        };
        init(ar,1,0,n-1);
    }
    segtree(vector<T> &ar, T _bc,T (*mfp)(T a,T b)) {
    	f = mfp;
        BASE_CASE=_bc;
    	n=ar.size();
        tree=vector<T>(4*n+1,0);
        init(ar,1,0,n-1);
    }
    T init(vector<T> &ar,int v,int tl,int tr){
        if (tl == tr)
            return tree[v] = ar[tl];
        
        int tm = (tl + tr) / 2;
        T a=init(ar, v*2, tl, tm);
        T b=init(ar, v*2+1, tm+1, tr);
        return tree[v] = f(a,b);
    }
    T ask(int l,int r){
        return _ask(1,0,n-1,l,r);
    }
    T _ask(int v,int tl,int tr,int l,int r){
        if(l>r)
            return BASE_CASE;
        if(l==tl&&r==tr)
            return tree[v];
        int tm=(tl+tr)/2;
        T a=_ask(v*2, tl, tm, l, min(r, tm));
        T b=_ask(v*2+1, tm+1, tr, max(l, tm+1), r);
        return f(a,b);
    }
    void update(int idx, T val){
        _update(1,0,n-1,idx,val);
    }
    void _update(int v,int tl,int tr,int idx,T val){
        if(tl==tr){
            tree[v]=val;
            return;
        }
        int tm=(tl+tr)/2;
        if(idx<=tm)
            _update(v*2,tl,tm,idx,val);
        else
            _update(v*2+1,tm+1,tr,idx,val);
        tree[v]=f(tree[v*2],tree[v*2+1]);
    }
};

void torment() {
    ll n;
    cin>>n;
    vll ar(n);
    fin(i,0,n) {
        cin>>ar[i];
    }
    segtree<ll> st(ar,0,[](ll a,ll b){
        return __gcd(a,b);
    });
    ll q;
    cin>>q;
    fin(i,0,q) {
        ll l,r;
        cin>>l>>r;
        cout<<st.ask(l,r)<<endl;
    }
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

// anger, happiness and sadness
// won't mean a thing when...
