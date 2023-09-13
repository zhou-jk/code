#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
using namespace std;
const int N=50005;
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
int getinv(int a)
{
    return qpow(a,MOD-2);
}
struct Matrix
{
    int n,m;
    int mat[11][11];
    Matrix()
    {
        n=m=0;
        memset(mat,0,sizeof(mat));
    }
    Matrix(int _n,int _m)
    {
        n=_n,m=_m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mat[i][j]=0;
    }
    void resize(int _n,int _m)
    {
        n=_n,m=_m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mat[i][j]=0;
        return;
    }
    friend Matrix operator*(const Matrix &a,const Matrix &b)
    {
        assert(a.m==b.n);
        Matrix c(a.n,b.m);
        for(int k=0;k<a.m;k++)
            for(int i=0;i<min(k+1,a.n);i++)
                if(a.mat[i][k])
                    for(int j=k;j<b.m;j++)
                        if(b.mat[k][j]) c.mat[i][j]=(c.mat[i][j]+(long long)a.mat[i][k]*b.mat[k][j])%MOD;
        return c;
    }
};
int n,q;
const char t[]=" helloworld";
int p[256];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        Matrix c;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].c=tree[ls].c*tree[rs].c;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].c.resize(11,11);
            for(int j=0;j<=10;j++)
                tree[i].c.mat[j][j]=1;
            for(int j=1;j<=10;j++)
                tree[i].c.mat[j-1][j]=p[(int)t[j]];
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,char c)
    {
        if(tree[i].l==tree[i].r)
        {
            for(int j=1;j<=10;j++)
                if(c==t[j]) tree[i].c.mat[j-1][j]=1;
                else tree[i].c.mat[j-1][j]=0;
            return;
        }
        if(u<=tree[ls].r) modify(ls,u,c);
        else modify(rs,u,c);
        push_up(i);
        return;
    }
    void query(int i,int l,int r,Matrix &res)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            res=res*tree[i].c;
            return;
        }
        if(l<=tree[ls].r) query(ls,l,r,res);
        if(r>=tree[rs].l) query(rs,l,r,res);
        return;
    }
    #undef ls
    #undef rs
}T;
void solve()
{
    cin>>n;
    cin>>p['h']>>p['e']>>p['l']>>p['o']>>p['w']>>p['r']>>p['d'];
    int pt=p['h']+p['e']+p['l']+p['o']+p['w']+p['r']+p['d'],ptinv=getinv(pt);
    for(char ch:{'h','e','l','o','w','r','d'})
        p[(int)ch]=(long long)p[(int)ch]*ptinv%MOD;
    T.build(1,1,n);
    cin>>q;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x;
            char c;
            cin>>x>>c;
            T.modify(1,x,c);
        }
        else if(op==2)
        {
            int l,r;
            cin>>l>>r;
            Matrix res(1,11);
            res.mat[0][0]=1;
            T.query(1,l,r,res);
            cout<<res.mat[0][10]<<"\n";
        }
    }
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