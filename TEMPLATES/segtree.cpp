#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct segtree{
    int n;
    int BASE_CASE=0;
    vector<T> tree;
 
    T f(T a,T b){
        return a+b;
    }
 
    void build(int len,T* ar){
        n=len;
        tree=vector<T>(4*n+1,0);
        init(ar,1,0,n-1);
    }
 
    T init(T ar[],int v,int tl,int tr){
        if (tl == tr)
            return tree[v] = ar[tl];
        
        int tm = (tl + tr) / 2;
        T a=init(ar, v*2, tl, tm);
        T b=init(ar, v*2+1, tm+1, tr);
        return tree[v] = f(a,b);
    }
 
    T ask(int l,int r){
        return query(1,0,n-1,l,r);
    }
 
    T query(int v,int tl,int tr,int l,int r){
        if(l>r)
            return BASE_CASE;
        if(l==tl&&r==tr)
            return tree[v];
        int tm=(tl+tr)/2;
        T a=query(v*2, tl, tm, l, min(r, tm));
        T b=query(v*2+1, tm+1, tr, max(l, tm+1), r);
        return f(a,b);
    }
 
    void update(int idx, T val){
        update(1,0,n-1,idx,val);
    }
 
    void update(int v,int tl,int tr,int idx,T val){
        if(tl==tr){
            tree[v]=val;
            return;
        }
        int tm=(tl+tr)/2;
        if(idx<=tm)
            update(v*2,tl,tm,idx,val);
        else
            update(v*2+1,tm+1,tr,idx,val);
        tree[v]=f(tree[v*2],tree[v*2+1]);
    }
};

int main() {
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    segtree<int> st;
    st.build(n,ar);
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(s=="update"){
            int idx,newv;
            cin>>idx>>newv;
            st.update(idx-1,newv);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.ask(l-1,r-1)<<endl;
        }
    }
}
