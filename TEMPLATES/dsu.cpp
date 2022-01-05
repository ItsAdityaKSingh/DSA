#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct dsu{
    int N;
    vector<int> parent,c_size;
    dsu(int n){
        N=n;
        parent=vector<int>(N);
        c_size=vector<int>(N);
        for(int i=0;i<N;i++){
            parent[i]=i;
            c_size[i]=1;
        }
    }
    int search(int v){
        if(v==parent[v])
            return v;
        return parent[v]=search(parent[v]);
    }
    bool unite(int a,int b){
        a=search(a);
        b=search(b);
        if(a==b)
            return false;
        if(a!=b){
            if(c_size[a]<c_size[b]){
                a-=b;
                b+=a;
                a=b-a;
            }
            parent[b]=a;
            c_size[a]+=c_size[b];
        }
        return true;
    }
};

int main() {
    ll n,m;
    cin>>n>>m;
    dsu d(n);
    while(m--){
        ll a,b;
        cin>>a>>b;
        d.unite(--a,--b);
    }
    ll q;
    cin>>q;
    while(q--){
        ll a,b;
        cin>>a>>b;
        if(d.search(--a)==d.search(--b))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

