#include<iostream>
#include<cstdio>
#include<cassert>
#include<vector>
using namespace std;
const int MOD=1000000007;
struct Matrix
{
    int n,m;
    vector<vector<int>> mat;
    Matrix(){}
    Matrix(int _n,int _m):n(_n),m(_m)
    {
        mat.resize(n);
        for(int i=0;i<n;i++)
            mat[i].resize(m);
    }
    void resize(int _n,int _m)
    {
        n=_n,m=_m;
        mat.resize(n);
        for(int i=0;i<n;i++)
            mat[i].resize(m);
        return;
    }
    void clear()
    {
        mat.clear();
        mat.resize(n);
        for(int i=0;i<n;i++)
            mat[i].resize(m);
        return;
    }
    const vector<int>& operator[](const int &i)const
    {
        return mat[i];
    }
    vector<int>& operator[](const int &i)
    {
        return mat[i];
    }
    friend Matrix operator * (const Matrix &a,const Matrix &b)
    {
        assert(a.m==b.n);
        Matrix c(a.n,b.m);
        for(int i=0;i<a.n;i++)
            for(int j=0;j<b.m;j++)
                for(int k=0;k<a.m;k++)
                    c[i][j]=(c[i][j]+(long long)a[i][k]*b[k][j])%MOD;
        return c;
    }
};
Matrix pw[60];
void init(long long n=1000000000000000000)
{
    pw[0].n=pw[0].m=6;
    pw[0].mat=
    {
        {1,1,0,0,0,0},
        {2,0,1,1,1,0},
        {1,0,0,0,0,0},
        {2,0,0,0,1,0},
        {2,0,0,0,0,1},
        {0,0,0,1,0,0}
    };
    for(int i=1;(1LL<<i)<=n;i++)
        pw[i]=pw[i-1]*pw[i-1];
    return;
}
long long n;
void solve()
{
    cin>>n;
    if(n==1) cout<<1<<"\n";
    else if(n==2) cout<<3<<"\n";
    else if(n==3) cout<<10<<"\n";
    else
    {
        Matrix res(1,6);
        res.mat={{10,3,1,1,2,1}};
        n-=3;
        for(int i=__lg(n);i>=0;i--)
            if((n>>i)&1) res=res*pw[i];
        int ans=res[0][0];
        cout<<ans<<"\n";
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}