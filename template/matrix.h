#include<iostream>
#include<cstdio>
#include<cassert>
#include<vector>
#include"modint.h"
using namespace std;
struct Matrix
{
public:
    Matrix(int _n=0,int _m=0)
    {
        n=_n,m=_m;
        mat.resize(n+1);
        for(int i=1;i<=n;i++)
            mat[i].resize(m+1);
        return;
    }
    void resize(int _n=0,int _m=0)
    {
        n=_n,m=_m;
        mat.resize(n+1);
        for(int i=1;i<=n;i++)
            mat[i].resize(m+1);
        return;
    }
    void clear()
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                mat[i][j]=0;
        return;
    }
    modint det()const
    {
        if(n!=m) return -1;
        vector<vector<modint>>C=mat;
        int cur=1;
        modint res=1;
        for(int i=1;i<=m;i++)
        {
            int pos=cur;
            for(int j=cur;j<=n;j++)
                if(C[j][i].val()>C[pos][i].val()) pos=j;
            if(C[pos][i].val()==0) return 0;
            if(cur!=pos) swap(C[pos],C[cur]),res=-res;
            for(int j=cur+1;j<=n;j++)
                while(C[j][i].val())
                {
                    if(C[j][i].val()<C[cur][i].val()) swap(C[cur],C[j]),res=-res;
                    int d=C[j][i].val()/C[cur][i].val();
                    for(int k=i;k<=m;k++)
                        C[j][k]-=C[cur][k]*d;
                }
            res*=C[cur][i];
            cur++;
        }
        return res;
    }
    Matrix operator + (const Matrix &rhs)const
    {
        assert(n==rhs.n&&m==rhs.m);
        Matrix c(n,m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                c.mat[i][j]=mat[i][j]+rhs.mat[i][j];
        return c;
    }
    Matrix operator - (const Matrix &rhs)const
    {
        assert(n==rhs.n&&m==rhs.m);
        Matrix c(n,m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                c.mat[i][j]=mat[i][j]-rhs.mat[i][j];
        return c;
    }
    Matrix operator * (const Matrix &rhs)const
    {
        assert(m==rhs.n);
        int _n=n,_m=rhs.m;
        Matrix c(_n,_m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=rhs.m;j++)
                for(int k=1;k<=m;k++)
                    c.mat[i][j]+=mat[i][k]*rhs.mat[k][j];
        return c;
    }
    Matrix operator += (const Matrix &rhs)
    {
        return *this=*this+rhs;
    }
    Matrix operator -= (const Matrix &rhs)
    {
        return *this=*this-rhs;
    }
    Matrix operator *= (const Matrix &rhs)
    {
        return *this=*this*rhs;
    }
    vector<modint> & operator [](const int &i)
    {
        return mat[i];
    }
private:
    int n,m;
    vector<vector<modint>>mat;
};