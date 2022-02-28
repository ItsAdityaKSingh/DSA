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

template<typename T>
struct spt {
    int _n;
    int _log = 0;
    vector<vector<T>> table; 
    vector<int> logs;

    T (*f)(T a,T b) = [](T a, T b)->T{
        return min(a, b);
    };

    spt(vector<T> ar) {
        _n = ar.size();
        while(1<<_log < _n) 
            _log++;
        table = vector<vector<T>>(_log, vector<T>(_n, 0));
        logs = vector<int>(_n + 1);
        build(ar);
    }

    spt(vector<T> ar, T (*mfp)(T a,T b)) {
        f = mfp;
        _n = ar.size();
        while(1<<_log < _n)
            _log++;
        table = vector<vector<T>>(_log, vector<T>(_n, 0));
        logs = vector<int>(_n + 1);
        build(ar);
    }

    void build(vector<T> &ar) {
        logs[1] = 0;
        for(int i=2;i<_n+1;i++) 
            logs[i]=logs[i/2]+1;

        for(int len=0;len<_log;len++) {
            for(int i=0;i+(1<<len)-1<_n;i++) {
                if(len==0) {
                    table[len][i]=ar[i];
                    continue;
                }
                table[len][i]=f(table[len-1][i], table[len-1][i+(1<<(len-1))]);
            }
        }
    }

    T ask(int l, int r) {
        int len = r-l+1;
        int k = logs[len];
        return f(table[k][l], table[k][r-(1<<k)+1]);
    }
};

void torment() {
    ll n;
    cin >> n;
    vll v(n);
    fin(i, 0, n) {
        v[i]=rand()%n+1;
    }
    spit(v);
    spt<ll> s(v);
    ll q;
    cin >> q;
    while(q--) {
        ll l, r;
        cin >> l >> r;
        cout << s.ask(l, r) << endl;
    }
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
