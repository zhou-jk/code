#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N=105;
const double eps=1e-8;
struct Matrix
{
    int n,m;
    double mat[N][N];
    Matrix(int _n=0,int _m=0)
    {
        n=_n,m=_m;
        memset(mat,0,sizeof(mat));
        return;
    }
    void clear()
    {
        memset(mat,0,sizeof(mat));
        return;
    }
    void gauss()
    {
        int cur=1;
        for(int i=1;i<=m;i++)
        {
            int pos=cur;
            for(int j=cur;j<=n;j++)
                if(fabs(mat[j][i])>fabs(mat[pos][i])) pos=j;
            if(fabs(mat[pos][i])<eps) continue;
            swap(mat[cur],mat[pos]);
            for(int j=1;j<=n;j++)
                if(j!=cur)
                {
                    double d=mat[j][i]/mat[cur][i];
                    for(int k=i;k<=m;k++)
                        mat[j][k]-=mat[cur][k]*d;
                    mat[j][i]=0;
                }
            cur++;
        }
        return;
    }
};
int main()
{
    int n;
    scanf("%d",&n);
    Matrix M(n,n+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n+1;j++)
            scanf("%lf",&M.mat[i][j]);
    M.gauss();
    for(int i=1;i<=n;i++)
        if(fabs(M.mat[i][i])<eps)
        {
            printf("No Solution");
            return 0;
        }
    for(int i=1;i<=n;i++)
        printf("%.2lf\n",M.mat[i][n+1]/M.mat[i][i]);
    return 0;
}