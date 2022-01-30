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
    // base case
    // 0 for addition, gcd, xor
    // 1 for multiplication
    // -inf for max
    // inf for min
    // etc
    int BASE_CASE=0;
    vector<T> tree;

    // constructor
    segtree(vector<T> &ar){
        n=ar.size();
        tree=vector<T>(4*n+1,0);
        init(ar,1,0,n-1);
    }

    // associative func
    // change as per need to
    // __gcd(a,b), a*b, a^b,min,max etc
    T f(T a,T b){
        return a+b;
    }

    T init(vector<T> &ar,int v,int tl,int tr){
        if (tl == tr)
            return tree[v] = ar[tl];
        
        int tm = (tl + tr) / 2;
        T a=init(ar, v*2, tl, tm);
        T b=init(ar, v*2+1, tm+1, tr);
        return tree[v] = f(a,b);
    }

    // black box:
    // gives value of function f for range [l,r]
    // l and r shud be 0 indexed
    // eg st.ask(l,r)
    T ask(int l,int r){
        return _ask(1,0,n-1,l,r);
    }
    // black box:
    // change the value at idx to val
    // idx has 0 indexing
    void update(int idx, T val){
        _update(1,0,n-1,idx,val);
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

int32_t main() {
    ll n;
    cin>>n;
    vector<ll> ar(n);
    fin(i,0,n)
    	cin>>ar[i];
    // instanciating segtree from ar
    segtree<ll> st(ar);
    ll q;
    cin>>q;
    while(q--) {
    	ll type;
    	cin>>type;
    	if(type) {
    		ll l,r;
    		cin>>l>>r;
    		// query for value of associative
    		// func b/w l and r
    		cout<<st.ask(l,r)<<endl;
    	} else {
    		ll idx,val;
    		cin>>idx>>val;
    		// change value at idx to val
    		st.update(idx,val);
    	}
    }
}