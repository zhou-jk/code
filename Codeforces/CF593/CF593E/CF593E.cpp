#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=21;
const int MOD=1000000007;
const int dir[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
int h,w,n,Q;
bool book[N][N];
struct Matrix
{
    int n,m;
    long long mat[N][N];
    Matrix()
    {
        memset(mat,0,sizeof(mat));
        return;
    }
    Matrix operator * (const Matrix &b)const
    {
        Matrix res;
        res.n=n,res.m=b.m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=b.m;j++)
                for(int k=1;k<=m;k++)
                    res.mat[i][j]=(res.mat[i][j]+mat[i][k]*b.mat[k][j]%MOD)%MOD;
        return res;
    }
    friend Matrix ksm(Matrix a,long long b)
    {
        Matrix res;
        res.n=a.n,res.m=a.n;
        for(int i=1;i<=a.n;i++)
            res.mat[i][i]=1;
        while(b)
        {
            if(b&1) res=res*a;
            a=a*a,b>>=1;
        }
        return res;
    }
};
void build(Matrix &a)
{
    memset(a.mat,0,sizeof(a.mat));
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            if(book[i][j])
                for(int k=0;k<=4;k++)
                {
                    int x=i+dir[k][0],y=j+dir[k][1];
                    if(x<1||x>h||y<1||y>w) continue;
                    if(!book[x][y]) continue;
                    a.mat[(i-1)*w+j][(x-1)*w+y]=1;
                }
    return;
}
int main()
{
    scanf("%d%d%d",&h,&w,&Q);
    n=h*w;
    int now=1;
    Matrix ans,a;
    ans.n=n,ans.m=1;
    a.n=n,a.m=n;
    ans.mat[1][1]=1;
    memset(book,true,sizeof(book));
    while(Q--)
    {
        int op,x,y,t;
        scanf("%d%d%d%d",&op,&x,&y,&t);
        build(a);
        ans=(ksm(a,t-now))*ans;
        now=t;
        if(op==1) printf("%lld\n",ans.mat[(x-1)*w+y][1]);
        if(op==2) ans.mat[(x-1)*w+y][1]=0,book[x][y]=false;
        if(op==3) ans.mat[(x-1)*w+y][1]=0,book[x][y]=true;
    }
    return 0;
}