#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=305;
const int MOD=1000000007;
int n;
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
        if(n!=m) return -1;
        vector<vector<int>>C=mat;
        int cur=1;
        int res=1;
        for(int i=1;i<=m;i++)
        {
            int pos=cur;
            for(int j=cur;j<=n;j++)
                if(C[j][i]>C[pos][i]) pos=j;
            if(C[pos][i]==0) return 0;
            if(pos!=cur) swap(C[pos],C[cur]),res=-res;
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
    Matrix operator - (const Matrix &rhs)const
    {
        Matrix c(n,m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                c.mat[i][j]=((long long)mat[i][j]-rhs.mat[i][j]+MOD)%MOD;
        return c;
    }
};
int main()
{
    scanf("%d",&n);
    Matrix A(n,n),D(n,n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%1d",&A.mat[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            D.mat[i][i]+=A.mat[j][i];
    Matrix T=D-A;
    Matrix L(n-1,n-1);
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=n-1;j++)
            L.mat[i][j]=T.mat[i+1][j+1];
    printf("%d",L.det());
    return 0;
}