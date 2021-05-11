#include<iostream>
#include<cstdio>
#include<cassert>
#include<vector>
using namespace std;
namespace mod_int_define
{
int MOD;
void set_mod(const int &m)
{
    MOD=m;
    return;
}
int mod()
{
    return MOD;
}
struct modint
{
public:
    modint(const int &x=0)
    {
        v=(x%MOD+MOD)%MOD;
        return;
    }
    modint(const long long &x)
    {
        v=(x%MOD+MOD)%MOD;
        return;
    }
    modint operator = (const int &x)
    {
        v=(x%MOD+MOD)%MOD;
        return *this;
    }
    modint operator = (const long long &x)
    {
        v=(x%MOD+MOD)%MOD;
        return *this;
    }
    int val()const
    {
        return v;
    }
    modint operator + (const modint &rhs)const
    {
        modint c;
        c.v=(v+rhs.v);
        if(c.v>=MOD) c.v-=MOD;
        return c;
    }
    modint operator - (const modint &rhs)const
    {
        modint c;
        c.v=(v-rhs.v);
        if(c.v<0) c.v+=MOD;
        return c;
    }
    modint operator * (const modint &rhs)const
    {
        modint c;
        c.v=1LL*v*rhs.v%MOD;
        return c;
    }
    friend modint pow(const modint &aa,const int &bb)
    {
        modint a=aa;
        int b=bb;
        modint res=1;
        while(b)
        {
            if(b&1) res=res*a;
            a=a*a,b>>=1;
        }
        return res;
    }
    modint operator / (const modint &rhs)const
    {
        modint c=*this*rhs.getinv();
        return c;
    }
    modint operator += (const modint &rhs)
    {
        return *this=*this+rhs;
    }
    modint operator -= (const modint &rhs)
    {
        return *this=*this-rhs;
    }
    modint operator *= (const modint &rhs)
    {
        return *this=*this*rhs;
    }
    modint operator /= (const modint &rhs)
    {
        return *this=*this/rhs;
    }
    modint operator == (const modint &rhs)const
    {
        return v==rhs.v;
    }
    modint operator != (const modint &rhs)const
    {
        return v!=rhs.v;
    }
    modint operator ++ ()
    {
        v++;
        if(v>=MOD) v-=MOD;
        return *this;
    }
    modint operator -- ()
    {
        v--;
        if(v<0) v+=MOD;
        return *this;
    }
    modint operator - ()const
    {
        modint c;
        c.v=-v;
        if(c.v<0) c.v+=MOD;
        return c;
    }
protected:
    modint getinv()const
    {
        return pow(*this,MOD-2);
    }
private:
    int v;
};
}
using mod_int_define::set_mod;
using mod_int_define::mod;
using mod_int_define::modint;
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
            if(cur!=pos) swap(C[cur],C[pos]),res=-res;
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
int n,m,t;
namespace Subtask1
{
Matrix A,D;
int main()
{
    set_mod(1000000007);
    A.resize(n,n),D.resize(n,n);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u==v) continue;
        A[u][v]+=w;
        A[v][u]+=w;
        D[u][u]+=w,D[v][v]+=w;
    }
    Matrix T=D-A;
    Matrix L(n-1,n-1);
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=n-1;j++)
            L[i][j]=T[i+1][j+1];
    L.resize(n-1,n-1);
    printf("%d",L.det().val());
    return 0;
}
}
namespace Subtask2
{
Matrix A,D;
int main()
{
    set_mod(1000000007);
    A.resize(n,n),D.resize(n,n);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u==v) continue;
        A[u][v]+=w;
        D[v][v]+=w;
    }
    Matrix T=D-A;
    Matrix L(n-1,n-1);
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=n-1;j++)
            L[i][j]=T[i+1][j+1];
    printf("%d",L.det().val());
    return 0;
}
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    if(t==0) return Subtask1::main();
    else if(t==1) return Subtask2::main();
    return 0;
}