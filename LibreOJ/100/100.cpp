#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=501;
const int MOD=1000000007;
int n,p,m;
struct Matrix
{
    long long C[N][N];
    Matrix ()
    {
        memset(C,0,sizeof(C));
        return;
    }
    Matrix operator*(const Matrix &b)const
    {
        Matrix res;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int k=1;k<=p;k++)
                    res.C[i][j]=((res.C[i][j]+C[i][k]*b.C[k][j]%MOD)%MOD+MOD)%MOD;
        return res;
    }
}a,b,c;
int main()
{
    scanf("%d%d%d",&n,&p,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=p;j++)
            scanf("%lld",&a.C[i][j]);
    for(int i=1;i<=p;i++)
        for(int j=1;j<=m;j++)
            scanf("%lld",&b.C[i][j]);
    c=a*b;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%lld ",c.C[i][j]);
        printf("\n");
    }
    return 0;
}