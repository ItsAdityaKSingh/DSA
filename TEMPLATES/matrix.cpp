#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct matrix {
    int rows=0;
    int cols=0;
    vector<vector<T>> v;

    ////// basics
    // constructor
    matrix(){};
    matrix(int n,int m){
        rows=n;
        cols=m;
        v=vector<vector<T>>(rows,vector<T>(cols,0));
    };
    void resize(int n,int m){
        rows=n;
        cols=m;
        v=vector<vector<T>>(rows,vector<T>(cols,0));
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
    // void debug(){
    //     dbg(rows,cols);
    //     cout<<endl;
    //     fin(i,0,rows){
    //         fin(j,0,cols)
    //             cout<<v[i][j]<<" ";
    //         cout<<endl;
    //     }
    //     cout<<endl<<endl;
    // }

    ////// matrix methods
    // construct identity matrix of order n
    matrix<T> identity(int n){
        matrix<T> res(n,n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                res.v[i][j]=(i==j?1:0);
        return res;
    }
    // matrix multiplication
    matrix<T> multiply(matrix<T> a,matrix<T> b){
        if(a.cols!=b.rows){
            cerr<<"error: invalid operands for matrix multiplication\n";
            exit(0);
        }
        matrix<T> res(a.rows,b.cols);
        for(int i=0;i<a.rows;i++){
            for(int j=0;j<b.cols;j++){
                res.v[i][j]=0;
                T sum=0;
                for(int k=0;k<min(a.cols,b.rows);k++){
                    res.v[i][j]+=a.v[i][k]*b.v[k][j];
                    sum+=a.v[i][k]*b.v[k][j];
                }
            }
        }
        return res;
    };
    // row reduced echelon form
    matrix<T> RRE(){
        matrix<T> res(rows,cols);
        res.v=v;
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
            for(int j=0;j<res.rows;j++) {
                if(j==i)
                    continue;
                T fac=res.get(j,idx);
                if(fac==0)
                    continue;
                for(int k=0;k<res.cols;k++)
                    res.v[j][k]-=res.v[i][k]*fac;
            }
        }
        return res;
    }

    matrix<T> gauss_jordan(){
        matrix<T> gj(rows,2*cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<rows;j++){
                gj.v[i][rows+j]=(i==j?1:0);
                gj.v[i][j]=v[i][j];
            }
        }
        return gj.RRE();
    }

    // get inverse
    matrix<T> inverse(){
        if(rows!=cols){
            cerr<<"error: invalid operand for inverse\n";
            exit(0);
        }
        matrix<T> gj=gauss_jordan();
        matrix<T> res(rows,rows);
        for(int i=0;i<rows;i++){
            for(int j=0;j<rows;j++){
                res.v[i][j]=gj.v[i][rows+j];
            }
        }
        return res;
    }
    // todo: add support for matrix<fraction>
};


int32_t main() {
    int n1,m1,n2,m2;
    cin>>n1>>m1;
    matrix<double> X1(n1,m1);
    X1.build();
    cin>>n2>>m2;
    matrix<double> X2(n2,m2);
    X2.build();
    X1.RRE().print();
    X1.inverse().print();
    X1.inverse().inverse().print();
    X1.multiply(X1,X2).print();
}