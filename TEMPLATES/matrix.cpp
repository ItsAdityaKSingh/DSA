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

    // get inverse
    matrix<T> inverse(){
        int n=rows;
        matrix<T> A(n,n);
        A.v=v;
        matrix<T> _INV=identity(n);
        matrix<T> I=_INV;
        matrix<T> _RRE=A;

        vector<int> ind(n);
        for(int i=0;i<n;i++)
            ind[i]=i;
        sort(ind.begin(),ind.end(),[&](int i1,int i2){
            vector<T> x=A.v[i1];
            vector<T> y=A.v[i2];
            for(int i=0;i<n;i++){
                if(x[i]&&!y[i])
                    return true;
                if(y[i]&&!x[i])
                    return false;
            }
            return x[0]<y[0];
        });
        for(int i=0;i<n;i++){
            _INV.v[i]=I.v[ind[i]];
            _RRE.v[i]=A.v[ind[i]];
        }
        for(int i=0;i<n;i++){
            T LNZ=0;
            int idx=-1;
            for(int j=0;j<n;j++){
                if(_RRE.get(i,j)!=0){
                    LNZ=_RRE.get(i,j);
                    idx=j;
                    break;
                }
            }
            if(idx==-1)
                continue;
            for(int j=0;j<n;j++){
                _RRE.v[i][j]/=LNZ;
                _INV.v[i][j]/=LNZ;
            }

            for(int j=0;j<n;j++){
                if(j==i)
                    continue;
                T fac=_RRE.get(j,idx);
                if(!fac)
                    continue;
                for(int k=0;k<n;k++){
                    _RRE.v[j][k]-=fac*_RRE.v[idx][k];
                    _INV.v[j][k]-=fac*_INV.v[idx][k];
                }
            }
        }
        return _INV;
    }
// BUG in inverse
// -0.259259 0.777778 -0.074074 
// 0.370370 -0.111111 -0.037037 
// 0.148148 -0.444444 0.185185 

// 1 3 1
// 2 1 1
// 4 0 7
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
    X1.multiply(X1,X2).print();
}