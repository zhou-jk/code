#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=15;
const int MOD=1000000000;
int n,m;
char s[N][N];
int id[N][N];
struct Matrix
{
    int n,m;
    vector<vector<int>>mat;
    Matrix(int _n=0,int _m=0)
    {
        n=_n,m=_m;
        mat.resize(n+1);
        for(int i=1;i<=n;i++)
            mat[i].resize(m+1);
        return;
    }
    void resize(int _n,int _m)
    {
        n=_n,m=_m;
        mat.resize(n+1);
        for(int i=1;i<=n;i++)
            mat[i].resize(m+1);
        return;
    }
    int det()const
    {
        vector<vector<int>>C=mat;
        int cur=1;
        int res=1;
        for(int i=1;i<=m;i++)
        {
            int pos=cur;
            for(int j=cur;j<=n;j++)
                if(C[j][i]>C[pos][i]) pos=j;
            if(C[pos][i]==0) return 0;
            if(cur!=pos) swap(C[pos],C[cur]),res=-res;
            for(int j=cur+1;j<=n;j++)
                while(C[j][i])
                {
                    if(C[j][i]<C[cur][i]) swap(C[j],C[cur]),res=-res;
                    int d=C[j][i]/C[cur][i];
                    for(int k=i;k<=m;k++)
                        C[j][k]=(C[j][k]-1LL*C[cur][k]*d%MOD+MOD)%MOD;
                    
                }
            res=1LL*res*C[cur][i]%MOD;
            cur++;
        }
        res=(res+MOD)%MOD;
        return res;
    }
    Matrix operator + (const Matrix &rhs)const
    {
        Matrix c(n,m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                c.mat[i][j]=mat[i][j]+rhs.mat[i][j];
        return c;
    }
    Matrix operator - (const Matrix &rhs)const
    {
        Matrix c(n,m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                c.mat[i][j]=mat[i][j]-rhs.mat[i][j];
        return c;
    }
};
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    int tot=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='.') id[i][j]=++tot;
    Matrix D(tot,tot),A(tot,tot);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m-1;j++)
            if(s[i][j]=='.'&&s[i][j+1]=='.')
            {
                A.mat[id[i][j]][id[i][j+1]]++;
                A.mat[id[i][j+1]][id[i][j]]++;
                D.mat[id[i][j]][id[i][j]]++;
                D.mat[id[i][j+1]][id[i][j+1]]++;
            }
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='.'&&s[i+1][j]=='.')
            {
                A.mat[id[i][j]][id[i+1][j]]++;
                A.mat[id[i+1][j]][id[i][j]]++;
                D.mat[id[i][j]][id[i][j]]++;
                D.mat[id[i+1][j]][id[i+1][j]]++;
            }
    Matrix L=D-A;
    L.resize(tot-1,tot-1);
    printf("%d",L.det());
    return 0;
}