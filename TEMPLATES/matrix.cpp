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
struct mat{
	int rows;
    int cols;
	vector<vector<T>> v;
	mat(int _rows,int _cols) {
		rows = _rows;
        cols = _cols;
		v=vector<vector<T>>(rows,vector<T>(cols,0));
	}
    vll &operator [](int i) {
        return v[i];
    }
    mat operator *(mat other) {
        // cur * other
        // cur.cols == other.rows
        mat res(rows,other.cols);
        fin(i,0,rows) 
            fin(j,0,other.cols) 
                fin(k,0,cols) 
                    res[i][j]=(res[i][j]+v[i][k]*other[k][j])%m420;
        return res;
    }
    mat operator *(ll other) {
        mat res(rows, cols);
        fin(i,0,rows)
            fin(j,0,cols)
                res[i][j]=v[i][j]*other;
        return res;
    }
    mat operator +(mat other) {
        mat<ll> res(rows,cols);
        fin(i,0,rows)
            fin(j,0,cols)
                res[i][j]=v[i][j]+other[i][j];
        return res;
    } 
    void print() const{
        fin(i,0,rows)
            spit(v[i]);
        cout<<"\n";
    }
};

mat<ll> rand_mat(ll r,ll c,ll mn,ll mx) {
    mat<ll> res(r,c);
    fin(i,0,r) {
        fin(j,0,c) {
            res[i][j]=(mn + (mx-mn)*(1.0*rand()/RAND_MAX));
        }
    }
    return res;
}

void torment() {
    ll n,mn,mx;
    cin>>n>>mn>>mx;
    mat<ll> A=rand_mat(n,n,mn,mx);
    mat<ll> B=rand_mat(n,n,mn,mx);
    A.print();
    B.print();
    (A+B).print();
    (A*B).print();
    (B*A).print();
}

int32_t main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int32_t wrong_answer_on_pretest_2=1;
    cin>>wrong_answer_on_pretest_2;
    while(wrong_answer_on_pretest_2--){
        torment();
    }
}

// anger, happiness and sadness
// won't mean a thing when...
