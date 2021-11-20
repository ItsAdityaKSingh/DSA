#include<bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T>
struct DSU{
    int N;
    vector<int> parent,c_size;
    void init(int n){
        N=n;
        parent=vector<int>(N);
        c_size=vector<int>(N);
        for(int i=0;i<N;i++){
            parent[i]=i;
            c_size[i]=1;
        }
    }

    int find_set(int v){
        if(v==parent[v])
            return v;
        return parent[v]=find_set(parent[v]);
    }

    void union_sets(int a,int b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(c_size[a]<c_size[b]){
                a-=b;
                b+=a;
                a=b-a;
            }
            parent[b]=a;
            c_size[a]+=c_size[b];
        }
    }
};


int main() {
    ll n,m;
    cin>>n>>m;
    DSU<int> d;
    d.init(n);
    while(m--){
        ll a,b;
        cin>>a>>b;
        d.union_sets(--a,--b);
    }
    ll q;
    cin>>q;
    while(q--){
        ll a,b;
        cin>>a>>b;
        if(d.find_set(--a)==d.find_set(--b))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

