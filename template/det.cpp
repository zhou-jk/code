#include<iostream>
#include<cstdio>
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
const int N=605;
int P;
struct Matrix
{
    int n,m;
    vector<vector<modint>>mat;
    Matrix(int _n=0,int _m=0)
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
};
int main()
{
    int n;
    scanf("%d%d",&n,&P);
    set_mod(P);
    Matrix M(n,n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            M.mat[i][j]=x;
        }
    printf("%d",M.det().val());
    return 0;
}