#include<iostream>
#include<cstdio>
#include<cassert>
#include<vector>
using namespace std;
const int MOD=1000000007;
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(long long)res*a%MOD;
        a=(long long)a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return qpow(x,MOD-2);
}
struct Matrix
{
    int n,m;
    vector<vector<int>>mat;
    Matrix(int _n=0,int _m=0)
    {
        n=_n,m=_m;
        mat=vector<vector<int>>(n,vector<int>(m,0));
    }
    void resize(int _n,int _m)
    {
        n=_n,m=_m;
        mat=vector<vector<int>>(n,vector<int>(m,0));
    }
    const vector<int>& operator [](const int &x)const
    {
        return mat[x];
    }
    vector<int>& operator [](const int &x)
    {
        return mat[x];
    }
    friend Matrix operator *(const Matrix &a,const Matrix &b)
    {
        Matrix c(a.n,b.m);
        assert(a.m==b.n);
        for(int i=0;i<a.n;i++)
            for(int j=0;j<b.m;j++)
                for(int k=0;k<a.m;k++)
                    c[i][j]=(c[i][j]+(long long)a[i][k]*b[k][j])%MOD;
        return c;
    }
};
Matrix qpow(Matrix a,int b)
{
    assert(a.n==a.m);
    Matrix res(a.n,a.m);
    for(int i=0;i<a.n;i++)
        res[i][i]=1;
    while(b)
    {
        if(b&1) res=res*a;
        a=a*a,b>>=1;
    }
    return res;
}
int n,x,k;
void solve()
{
    cin>>n>>x>>k;
    int ans=(long long)(x+k)*qpow(2*k+1,n-1)%MOD;
    Matrix a(x,x);
    for(int i=0;i<x;i++)
        for(int j=0;j<x;j++)
            if(abs(i-j)<=k) a[i][j]=1;
            else a[i][j]=0;
    Matrix z(x,1);
    for(int i=0;i<x;i++)
        z[i][0]=1;
    Matrix res=qpow(a,n-1);
    z=res*z;
    for(int i=0;i<x;i++)
        ans=(ans-z[i][0]+MOD)%MOD;
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}