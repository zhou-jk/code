#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=55;
const double eps=1e-8;
int n;
double G[N][N];
struct Matrix
{
    int n,m;
    vector<vector<double>>mat;
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
    double det()const
    {
        if(n!=m) return -1;
        vector<vector<double>>C=mat;
        int cur=1;
        double res=1;
        for(int i=1;i<=m;i++)
        {
            int pos=cur;
            for(int j=cur;j<=n;j++)
                if(C[j][i]>C[pos][i]) pos=j;
            if(C[pos][i]<eps) return 0;
            if(pos!=cur) swap(C[pos],C[cur]),res=-res;
            for(int j=cur+1;j<=n;j++)
                if(C[j][i]<eps)
                {
                    double d=C[j][i]/C[cur][i];
                    for(int k=i;k<=m;k++)
                        C[j][k]-=C[cur][k]*d;
                    C[j][i]=0;
                }
            res*=C[cur][i];
            cur++;
        }
        return res;
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lf",&G[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(G[i][j]==1) G[i][j]-=eps;
    Matrix A(n,n),D(n,n);
    double sum=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            {
                sum*=1-G[i][j];
                A.mat[i][j]=G[i][j]/(1-G[i][j]);
                A.mat[j][i]=G[i][j]/(1-G[i][j]);
                D.mat[i][i]+=G[i][j]/(1-G[i][j]);
                D.mat[j][j]+=G[i][j]/(1-G[i][j]);
            }
    Matrix L=D-A;
    L.resize(n-1,n-1);
    printf("%.8lf",sum*L.det());
    return 0;
}