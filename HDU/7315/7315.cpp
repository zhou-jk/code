#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cassert>
using namespace std;
const int MOD=998244353;
long long n,m;
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
    int mat[2][2];
    Matrix(){}
    Matrix(int _n,int _m)
    {
        n=_n,m=_m;
        memset(mat,0,sizeof(mat));
    }
    int* operator [](const int &i)
    {
        return mat[i];
    }
    const int* operator [](const int &i)const
    {
        return mat[i];
    }
    friend Matrix operator *(const Matrix &a,const Matrix &b)
    {
        assert(a.m==b.n);
        Matrix res(a.n,b.m);
        for(int i=0;i<a.n;i++)
            for(int j=0;j<b.m;j++)
                for(int k=0;k<a.m;k++)
                    res[i][j]=(res[i][j]+(long long)a[i][k]*b[k][j])%MOD;
        return res;
    }
};
void solve()
{
    cin>>n>>m;
    if(m==0)
    {
        cout<<0<<"\n";
        return;
    }
    n%=MOD;
    int invn=getinv(n);
    int r1=(n-2+MOD)*invn%MOD,r2=2ll*invn*invn%MOD;
    Matrix p(2,2);
    p[0][0]=r1,p[0][1]=0;
    p[1][0]=r2,p[1][1]=1;
    Matrix res(1,2);
    res[0][0]=res[0][1]=1;
    long long b=m;
    while(b)
    {
        if(b&1) res=res*p;
        p=p*p,b>>=1;
    }
    int ans=n*(1-res[0][0]+MOD)%MOD;
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