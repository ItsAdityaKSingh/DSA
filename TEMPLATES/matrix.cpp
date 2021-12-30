#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct matrix {
    int rows=0;
    int cols=0;
    vector<vector<T>> v;

    // constructor
    matrix(int n,int m){
        rows=n;
        cols=m;
        v=vector<vector<T>>(rows,vector<T>(cols));
    };

    // build matrix from stdin
    void build(){
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                cin>>v[i][j];
    };

    // access the element at (i,j)
    T get(int i,int j){
        return v[i][j];
    };

    // shape
    pair<int,int> shape(){
        return {rows,cols};
    };

    // print
    void print(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++)
                cout<<v[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    };
};

// matrix multiplaication
template<typename T>
matrix<T> multiply(matrix<T> a,matrix<T> b){
    if(a.cols!=b.rows){
        cerr<<"error: invalid operands for matrix multiplication\n";
        exit(0);
    }
    matrix<T> res(a.rows,b.cols);
    for(int i=0;i<a.rows;i++){
        for(int j=0;j<b.cols;j++){
            res.v[i][j]=0;
            for(int k=0;k<min(a.cols,b.rows);k++){
                res.v[i][j]+=a.v[i][k]*b.v[k][j];
            }
        }
    }
    return res;
};

// returns row reduced echelon form of given matrix
template<typename T>
matrix<T> RRE(matrix<T> a){
    matrix<T> res=a;
    sort(res.v.begin(),res.v.end(),[&](vector<T> x,vector<T> y){
        for(int i=0;i<x.size();i++){
            if(x[i]!=0&&y[i]==0)
                return true;
            else if(y[i]!=0&&x[i]==0)
                return false;
        }
        return x[0]<y[0];
    });

    for(int i=0;i<res.rows;i++){
        T LNZ=0;
        int idx=-1;
        for(int j=0;j<res.cols;j++){
            if(res.get(i,j)!=0){
                LNZ=res.get(i,j);
                idx=j;
                break;
            }
        }

        if(idx==-1)
            continue;

        for(int j=0;j<res.cols;j++)
            res.v[i][j]/=LNZ;
        
        for(int j=i+1;j<res.rows;j++) {
            T fac=res.get(j,idx);
            if(fac==0)
                continue;
            for(int k=0;k<res.cols;k++)
                res.v[j][k]-=res.v[i][k]*fac;
        }
    }
    return res;
}

int32_t main() {
    int n1,m1,n2,m2;

    cin>>n1>>m1;
    matrix<double> X1(n1,m1);
    X1.build();

    cin>>n2>>m2;
    matrix<double> X2(n2,m2);
    X2.build();

    matrix<double> X1_ech = RRE(X1);
    matrix<double> X1X2 = multiply(X1,X2);
    X1_ech.print();
    X1X2.print();
}